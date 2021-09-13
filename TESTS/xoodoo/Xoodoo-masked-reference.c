/*
Implementation by Ronny Van Keer, hereby denoted as "the implementer".

For more information, feedback or questions, please refer to our website:
https://keccak.team/

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/
*/

/* #define VERBOSE_LEVEL    0 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "Xoodoo.h"

uint32_t XoodooMask[12];

void Xoodoo_Initialize_Masks(uint32_t* masks) {
  int i;
  for(i=0;i<48;i++) {
    randbyte(&(((uint8_t*)masks)[i]));
  }
}


/* ---------------------------------------------------------------- */

void Xoodoo_StaticInitialize( void )
{
}

/* ---------------------------------------------------------------- */

void Xoodoo_Initialize(uint32_t *state)
{
    memset(state, 0, NLANES*sizeof(tXoodooLane));
}

/* ---------------------------------------------------------------- */

void Xoodoo_AddByte(void *state, unsigned char byte, unsigned int offset)
{
    assert(offset < NLANES*sizeof(tXoodooLane));
    ((unsigned char *)state)[offset] ^= byte;
}

/* ---------------------------------------------------------------- */

void Xoodoo_AddBytes(void *state, const unsigned char *data, unsigned int offset, unsigned int length)
{
    unsigned int i;

    assert(offset < NLANES*sizeof(tXoodooLane));
    assert(offset+length <= NLANES*sizeof(tXoodooLane));
    for(i=0; i<length; i++)
        ((unsigned char *)state)[offset+i] ^= data[i];
}

/* ---------------------------------------------------------------- */

void Xoodoo_OverwriteBytes(void *state, const unsigned char *data, unsigned int offset, unsigned int length)
{
    assert(offset < NLANES*sizeof(tXoodooLane));
    assert(offset+length <= NLANES*sizeof(tXoodooLane));
    memcpy((unsigned char*)state+offset, data, length);
}

/* ---------------------------------------------------------------- */

void Xoodoo_OverwriteWithZeroes(void *state, unsigned int byteCount)
{
    assert(byteCount <= NLANES*sizeof(tXoodooLane));
    memset(state, 0, byteCount);
}

/* ---------------------------------------------------------------- */

void Xoodoo_ExtractBytes(const void *state, unsigned char *data, unsigned int offset, unsigned int length)
{
    assert(offset < NLANES*sizeof(tXoodooLane));
    assert(offset+length <= NLANES*sizeof(tXoodooLane));
    memcpy(data, (unsigned char*)state+offset, length);
}

/* ---------------------------------------------------------------- */

void Xoodoo_ExtractAndAddBytes(const void *state, const unsigned char *input, unsigned char *output, unsigned int offset, unsigned int length)
{
    unsigned int i;

    assert(offset < NLANES*sizeof(tXoodooLane));
    assert(offset+length <= NLANES*sizeof(tXoodooLane));
    for(i=0; i<length; i++)
        output[i] = input[i] ^ ((unsigned char *)state)[offset+i];
}

/* ---------------------------------------------------------------- */

#if defined(VERBOSE_LEVEL)

static void Dump(char * text, tXoodooLane * a0, tXoodooLane * a1, unsigned int level)
{
    if (level == VERBOSE_LEVEL) {
    #if 0
        printf("%-8.8s ", text);
        printf("%u %u %u %u - ", a[0+0], a[0+1], a[0+2], a[0+3] );
        printf("%u %u %u %u - ", a[4+0], a[4+1], a[4+2], a[4+3] );
        printf("%u %u %u %u\n", a[8+0], a[8+1], a[8+2], a[8+3] );
        if ((level == 2) && !strcmp(text, "Rho-east"))
            printf("\n");
    #elif 0
        printf("%-8.8s ", text);
        printf("%08x %08x %08x %08x - ", a[0+0], a[0+1], a[0+2], a[0+3] );
        printf("%08x %08x %08x %08x - ", a[4+0], a[4+1], a[4+2], a[4+3] );
        printf("%08x %08x %08x %08x\n", a[8+0], a[8+1], a[8+2], a[8+3] );
    #else
        printf("%s\n", text);
        printf("a00 %08x, a01 %08x, a02 %08x, a03 %08x,\t\tb00 %08x, b01 %08x, b02 %08x, b03 %08x\n", a0[0+0], a0[0+1], a0[0+2], a0[0+3], a1[0+0], a1[0+1], a1[0+2], a1[0+3] );
        printf("a10 %08x, a11 %08x, a12 %08x, a13 %08x,\t\tb10 %08x, b11 %08x, b12 %08x, b13 %08x\n", a0[4+0], a0[4+1], a0[4+2], a0[4+3], a1[4+0], a1[4+1], a1[4+2], a1[4+3] );
        printf("a20 %08x, a21 %08x, a22 %08x, a23 %08x,\t\tb20 %08x, b21 %08x, b22 %08x, b23 %08x\n\n", a0[8+0], a0[8+1], a0[8+2], a0[8+3], a1[8+0], a1[8+1], a1[8+2], a1[8+3] );
    #endif
    }
}

#else

#define Dump(text, a0, a1, level)

#endif


static void fromBytesToWords(tXoodooLane *stateAsWords, const unsigned char *state)
{
    unsigned int i, j;

    for(i=0; i<NLANES; i++) {
        stateAsWords[i] = 0;
        for(j=0; j<sizeof(tXoodooLane); j++)
            stateAsWords[i] |= (tXoodooLane)(state[i*sizeof(tXoodooLane)+j]) << (8*j);
    }
}

static void fromWordsToBytes(unsigned char *state, const tXoodooLane *stateAsWords)
{
    unsigned int i, j;

    for(i=0; i<NLANES; i++)
        for(j=0; j<sizeof(tXoodooLane); j++)
            state[i*sizeof(tXoodooLane)+j] = (stateAsWords[i] >> (8*j)) & 0xFF;
}

static void Xoodoo_Round( tXoodooLane * a0, tXoodooLane * a1, tXoodooLane rc )
{
    unsigned int x, y;
    // Share 0
    tXoodooLane    b0[NLANES];
    tXoodooLane    p0[NCOLUMS];
    tXoodooLane    e0[NCOLUMS];
    // Share 1
    tXoodooLane    b1[NLANES];
    tXoodooLane    p1[NCOLUMS];
    tXoodooLane    e1[NCOLUMS];

    /* Theta: Column Parity Mixer */
    for (x=0; x<NCOLUMS; ++x)
        p0[x] = a0[index(x,0)] ^ a0[index(x,1)] ^ a0[index(x,2)];
    for (x=0; x<NCOLUMS; ++x)
        e0[x] = ROTL32(p0[(x-1)%4], 5) ^ ROTL32(p0[(x-1)%4], 14);
    for (x=0; x<NCOLUMS; ++x)
        for (y=0; y<NROWS; ++y)
            a0[index(x,y)] ^= e0[x];

    for (x=0; x<NCOLUMS; ++x)
        p1[x] = a1[index(x,0)] ^ a1[index(x,1)] ^ a1[index(x,2)];
    for (x=0; x<NCOLUMS; ++x)
        e1[x] = ROTL32(p1[(x-1)%4], 5) ^ ROTL32(p1[(x-1)%4], 14);
    for (x=0; x<NCOLUMS; ++x)
        for (y=0; y<NROWS; ++y)
            a1[index(x,y)] ^= e1[x];
    Dump("Theta", a0, a1, 2);

    /* Rho-west: plane shift */
    for (x=0; x<NCOLUMS; ++x) {
        b0[index(x,0)] = a0[index(x,0)];
        b0[index(x,1)] = a0[index(x-1,1)];
        b0[index(x,2)] = ROTL32(a0[index(x,2)], 11);
    }
    memcpy( a0, b0, sizeof(b0) );

    for (x=0; x<NCOLUMS; ++x) {
        b1[index(x,0)] = a1[index(x,0)];
        b1[index(x,1)] = a1[index(x-1,1)];
        b1[index(x,2)] = ROTL32(a1[index(x,2)], 11);
    }
    memcpy( a1, b1, sizeof(b1) );
    Dump("Rho-west", a0, a1, 2);
        
    /* Iota: round constant */
    a0[0] ^= rc;
    Dump("Iota", a0, a1, 2);

    /* Chi: non linear layer */
    for (x=0; x<NCOLUMS; ++x)
        for (y=0; y<NROWS; ++y)
            b0[index(x,y)] = a0[index(x,y)] ^ (~a0[index(x,y+1)] & a0[index(x,y+2)]) ^ (a0[index(x,y+1)] & a1[index(x,y+2)]);

    for (x=0; x<NCOLUMS; ++x)
        for (y=0; y<NROWS; ++y)
            b1[index(x,y)] = a1[index(x,y)] ^ (~a1[index(x,y+1)] & a1[index(x,y+2)]) ^ (a1[index(x,y+1)] & a0[index(x,y+2)]);
    memcpy( a0, b0, sizeof(b0) );
    memcpy( a1, b1, sizeof(b1) );
    Dump("Chi", a0, a1, 2);

    /* Rho-east: plane shift */
    for (x=0; x<NCOLUMS; ++x) {
        b0[index(x,0)] = a0[index(x,0)];
        b0[index(x,1)] = ROTL32(a0[index(x,1)], 1);
        b0[index(x,2)] = ROTL32(a0[index(x+2,2)], 8);
    }
    memcpy( a0, b0, sizeof(b0) );

    for (x=0; x<NCOLUMS; ++x) {
        b1[index(x,0)] = a1[index(x,0)];
        b1[index(x,1)] = ROTL32(a1[index(x,1)], 1);
        b1[index(x,2)] = ROTL32(a1[index(x+2,2)], 8);
    }
    memcpy( a1, b1, sizeof(b1) );
    Dump("Rho-east", a0, a1, 2);

}

static const uint32_t    RC[MAXROUNDS] = {
    _rc12,
    _rc11,
    _rc10,
    _rc9,
    _rc8,
    _rc7,
    _rc6,
    _rc5,
    _rc4,
    _rc3,
    _rc2,
    _rc1
};

void Xoodoo_Permute_Nrounds( void * state, uint32_t nr, uint32_t* masks)
{
    tXoodooLane        a0[NLANES];
    tXoodooLane        a1[NLANES];
    unsigned int    i;

    // Generate randon mask
    for(i=0;i<48;i++) {
        ((uint8_t*)a1)[i] = ((uint8_t*)masks)[i];
    }

    fromBytesToWords(a0, (const unsigned char *)state);
    // Apply mask
    for(i=0;i<NLANES;i++) {
      a0[i] ^= a1[i];
    }

    starttrigger();
    Xoodoo_Round(a0, a1, RC[MAXROUNDS - nr]);
    endtrigger();
    nr--;
    for (i = MAXROUNDS - nr; i < MAXROUNDS; ++i ) {
        Xoodoo_Round( a0, a1, RC[i] );
        Dump("Round", a0, a1, 1);
    }
    Dump("Permutation", a0, a1, 0);

    // Unmask
    for(i=0;i<NLANES;i++)
      a0[i] ^= a1[i];

    fromWordsToBytes((unsigned char *)state, a0);

}

void Xoodoo_Permute_6rounds( uint32_t * state, uint32_t* masks)
{
    Xoodoo_Permute_Nrounds( state, 6, masks );
}

void Xoodoo_Permute_12rounds( uint32_t * state, uint32_t* masks)
{
    Xoodoo_Permute_Nrounds( state, 12, masks );
}
