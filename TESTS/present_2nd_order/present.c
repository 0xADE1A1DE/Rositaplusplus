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

//Present code taken from http://www.lightweightcrypto.org/implementations.php. Author D. Klose.
// Include-file
#include<stdint.h>
#include "present.h"

byte sbox_p[16]={0xc,0x5,0x6,0xb,0x9,0x0,0xa,0xd,0x3,0xe,0xf,0x8,0x4,0x7,0x1,0x2};


void addroundkey_present(byte *state,byte *key)
{
    int i;
    for(i=0;i<8;i++)
        state[i] = state[i] ^ key[i+2];
}

void sbox_present(byte *state)
{
    byte i;
    for(i=0;i<8;i++)
        state[i] = sbox_p[state[i]>>4]<<4 | sbox_p[state[i] & 0xF];

}

void keyschedule_present(byte *key,int round)
{
    byte save1,save2;
    int i;

   		save1  = key[0];
		save2  = key[1];

		for(i=0;i<8;i++)
            key[i] = key[i+2];

		key[8] = save1;
		key[9] = save2;
		save1 = key[0] & 7;								//61-bit left shift

        for(i=0;i<9;i++)
			key[i] = key[i] >> 3 | key[i+1] << 5;

		key[9] = key[9] >> 3 | save1 << 5;
		key[9] = sbox_p[key[9]>>4]<<4 | (key[9] & 0xF);	//S-Box application

		if((round+1) % 2 == 1)							//round counter addition
			key[1] ^= 128;
		key[2] = ((((round+1)>>1) ^ (key[2] & 15)) | (key[2] & 240));

}

void permute_present(byte *state)
{
    int i;
    byte temp[8];
    for(i=0;i<8;i++)
    {
			temp[i] = 0;
	}

	for(i=0;i<64;i++)
	{
		byte position = (16*i) % 63;						//Artithmetic calculation of the pLayer
		if(i == 63)									//exception for bit 63
			position = 63;
		byte element_source		= i / 8;
		byte bit_source 			= i % 8;
		byte element_destination	= position / 8;
		byte bit_destination 	= position % 8;
		temp[element_destination] |= ((state[element_source]>>bit_source) & 0x1) << bit_destination;
    }

	for(i=0;i<=7;i++)
	{
		state[i] = temp[i];
	}
}


