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


//#include <stdio.h>
//#include <stdlib.h>
#include <stdint.h>

#include "../elmoasmfunctionsdef.h"

#include "present_masking.h" 
#include "present.h"

#define ALIGN __attribute__ ((aligned (4)))
#define PLT_SZ 8
#define KEY_SZ 8
#define STATE_SZ 48
#define INPUTDATA_SZ (1+16+(16+16)+(16+16) +3)  //aligned to 4

uint8_t inputdata[INPUTDATA_SZ];
/*
 * 4 byte align arrays to make sure we don't load invalid data
 * for state of byte-wise operations (ARM loads/stores 4 bytes
 * from addr & ~(0b11) when load/storing from address addr).
 * In ARM, Addresses that are not divisable by 4 are invalid when used
 * with wordwise instructions (ldr, str)
 */ 
volatile uint8_t input[PLT_SZ] ALIGN;
volatile uint8_t key[KEY_SZ] ALIGN;
volatile int domask=1;

extern void runrand();
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
    volatile uint8_t arr[1024];
    int i=0;
    for (i=0;i<1024;i++)
    {
        arr[i] = 0;
    }
}

extern void printbyte(unsigned char * pointer);

void run_present_masked(uint8_t *input, uint8_t *key) {

  byte stateshare[3][16], keyshare[3][16];

  byte state[8];

  int i;

  // Comptue normal present for comparison
  for(i=0;i<8;i++) {
    state[i] = input[i];
    state[i] ^= key[i];
  }
  sbox_present(state);
  permute_present(state);

  // Share state
  share(stateshare, input, &inputdata[17+0]); 
  // Share key
  share(keyshare, key, &inputdata[17+32]);

  setinputdata(inputdata, INPUTDATA_SZ);
  // Compute 1 round of PRESENT
  //starttrigger();
  present_round(stateshare, keyshare);
  //endtrigger();

  unshare(input, stateshare);

  for(i=0;i<8;i++) {
    if(input[i] != state[i]) {
      printbyte(&i);
    }
  }
}

//static const uint8_t fixedinput[16] =   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static const uint8_t fixedkey[KEY_SZ] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
//static const uint8_t fixedkey[KEY_SZ] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf };

static const uint8_t fixedinput[PLT_SZ] = { /*@FIXED_INPUT{*/ 0xda, 0x39, 0xa3, 0xee, 0x5e, 0x6b, 0x4b, 0x0d/*}*/ };
//static const uint8_t fixedinput[PLT_SZ] = {  0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d };

void simple_init()
{
    int j=0;
    for(;j<STATE_SZ;j++)
    {
    }
}

//#define ROSITA_RAND_TEST
void simple_run()
{

    int i,j;

    // Use fixed key and fixed input as specified by CRI for use with AES
    //static const uint8_t fixedkey[16] = {0xf3, 0x34, 0x15, 0x6e, 0x32, 0x11, 0x23, 0xff, 0x53, 0x45, 0xde, 0xab, 0xb4, 0xb5, 0xd4, 0xa0};
    //static const uint8_t fixedkey[16] = {0x11, 0x43, 0x4e, 0xdd, 0x55, 0xa6, 0xcc, 0xef, 0x10, 0xde, 0x5d, 0x7f, 0xda, 0xbf, 0xdf, 0xff};


    for(i=0;i<NTRACES;i++)
    { 
	for (j=0;j<KEY_SZ;j++)
        {  
            key[j] = fixedkey[j];
        }
        unsigned char test;
        readrandombyte(&test);
        
        test = test & 0x01;
        //printgroup(&test);

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
        }
        else
        {
            for (j=0;j<PLT_SZ;j++)
            {    
                readrandombyte(&input[j]);
                inputdata[j+1] = input[j];
            }
            inputdata[0] = 1;
        }
        run_present_masked(input, key);
        //run_byte_xoodoo_masked_(input, key);
    }
    endprogram();
}
