// Copyright 2021 University of Adelaide
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#define NTRACES /*@NTRACES{*/ 10000 /*}*/
#define TEST_TRACES (NTRACES/2)


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bool2arith.h"
#include "../elmoasmfunctionsdef.h"
#define ALIGN __attribute__ ((aligned (4)))
#define PLT_SZ 16
#define KEY_SZ 16
#define STATE_SZ 1
#define INPUT_DATA_SZ 52 // 16b input, 4x8 masks, aligned to next 4th with space for group byte
/*
 * 4 byte align arrays to make sure we don't load invalid data
 * for state of byte-wise operations (ARM loads/stores 4 bytes
 * from addr & ~(0b11) when load/storing from address addr).
 * In ARM, Addresses that are not divisable by 4 are invalid when used
 * with wordwise instructions (ldr, str)
 */ 
volatile uint8_t input[PLT_SZ] ALIGN;
volatile uint8_t key[KEY_SZ] ALIGN;
uint8_t inputdata[INPUT_DATA_SZ];
volatile int domask=1;
uint32_t TMP0=0;
uint32_t TMP1=0;
extern void runrand();
volatile uint32_t Shares[3][STATE_SZ] ALIGN = {0};
volatile uint32_t Masks[8] ALIGN = {0};
uint8_t emptydata[16];
/* 
 * Clear stack using a volatile buffer so that at each run the stack
 * is the same otherwise content from the previous run ends up leaking
 * this can be also mitigated by running each test on a coin flip (this 
 * is the way how that the real world counterpart of this test is being run).
 * However, as this is a simulated run -- we know what state related effects
 * change affect the T-test values therefore we clear all state related 
 * interactions.
 */
void stack_clear()
{
    volatile uint8_t arr[4096];
    int i=0;
    for (i=0;i<4096;i++)
    {
        arr[i] = 0;
    }
}
void readrandword(uint32_t* word)
{
    uint8_t* b = (uint8_t*) word;
    readrandombyte(&b[0]);
    readrandombyte(&b[1]);
    readrandombyte(&b[2]);
    readrandombyte(&b[3]);
}
void MaskState()
{
    Masks[0] = 0;
    Masks[1] = 0;
    Masks[2] = 0;
    Masks[3] = 0;
    Masks[4] = 0;
    Masks[5] = 0;
    Masks[6] = 0;
    Masks[7] = 0;
    readrandword(&Masks[0]);
    readrandword(&Masks[1]);
    Shares[0][0] ^= Masks[0] ^ Masks[1]; 
    readrandword(&Masks[2]);
    readrandword(&Masks[3]);
    readrandword(&Masks[4]);
    readrandword(&Masks[5]);
    readrandword(&Masks[6]);
    readrandword(&Masks[7]);
}
void run_byte_sharetest_masked_(uint8_t ttest, uint8_t* inputbuf, uint8_t* keybuf)
{
    int i,j;
    
    Shares[0][0] = inputbuf[0] | (inputbuf[1] << 8) | (inputbuf[2] << 16) | (inputbuf[3] << 24);
    Shares[1][0] = 0;
    Shares[2][0] = 0;

    MaskState();
    for (j=0;j<8;j++)
    {
        inputdata[17+4*j] = Masks[j] & 0xff;
        inputdata[17+4*j+1] = (Masks[j]>>8)&0xff;
        inputdata[17+4*j+2] = (Masks[j]>>16)&0xff;
        inputdata[17+4*j+3] = (Masks[j]>>24)&0xff;
    }
    inputdata[49] = 0;
    inputdata[50] = 0;
    inputdata[51] = 0;
    setinputdata(inputdata, INPUT_DATA_SZ);

    runrand();

    stack_clear();

    uint32_t ax = Bool2Arith(Shares[0][0], &Masks[0]);
    ax -= Masks[2];
    ax -= Masks[3];

    // output data 
    printbyte(&ax);
    ax >>= 8;
    printbyte(&ax);
    ax >>= 8;
    printbyte(&ax);
    ax >>= 8;
    printbyte(&ax);
    
}


//static const uint8_t fixedinput[16] =   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const uint8_t fixedkey[KEY_SZ] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0	};

static const uint8_t fixedinput[PLT_SZ] = { /*@FIXED_INPUT{*/ 0xda, 0x39, 0xa3, 0xee, 0x5e, 0x6b, 0x4b, 0x0d, 0x32, 0x55, 0xbf, 0xef, 0x95, 0x60, 0x18, 0x90/*}*/ };

void simple_init()
{
    int j=0;
    for(;j<STATE_SZ;j++)
    {
    }
}

void simple_run()
{

    int i,j;


    for(i=0;i<NTRACES;i++)
    { 
	    for (j=0;j<KEY_SZ;j++)
        {  
            key[j] = fixedkey[j];
        }
        unsigned char test;
        
        if (i < (NTRACES/2))
        {
            for (j=0;j<PLT_SZ;j++)
            {
#ifdef ROSITA_RAND_TEST
                readrandombyte(&input[j]);
#else
                readrandombyte(&input[j]);
                input[j] = fixedinput[j];
#endif
                inputdata[j+1] = input[j];
            }
            inputdata[0] = 0;
            test = 0;
        }
        else
        {
            for (j=0;j<PLT_SZ;j++)
            {    
                readrandombyte(&input[j]);
                inputdata[j+1] = input[j];
            }
            inputdata[0] = 1;
            test = 1;
        }
        run_byte_sharetest_masked_(test, input, key);
    }
    endprogram();
}
