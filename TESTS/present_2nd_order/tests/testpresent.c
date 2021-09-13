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


#include <stdio.h>
#include <stdint.h>
#include "../present.h"
#include "../present_masking.h"
#define PLT_SZ 8
#define KEY_SZ 8

uint8_t input[PLT_SZ] = {0xFF};
uint8_t key[KEY_SZ] = {0xFF};

int main(int argc, char* argv[])
{
  byte inputdata[8] = {0,0,0,0, 0,0,0,0};
  byte key[8] = {0,0,0,0, 0,0,0,0};
  byte masks[3][16] = {12};
  byte stateshare[3][16], keyshare[3][16];

  byte state[8];

  int i,j;

  // Comptue normal present for comparison
  for(i=0;i<8;i++) {
    state[i] = input[i];
    state[i] ^= key[i];
  }

  // Share state
  share(stateshare, input, &masks[0][0]); 
  // Share key
  share(keyshare, key, &masks[0][0]);

  // Compute 1 round of PRESENT
  //starttrigger();
  
  for (j=0;j<32;j++)
  {
    sbox_present(state);
    permute_present(state);

    present_round(stateshare, keyshare);
    //endtrigger();

    unshare(input, stateshare);

    for(i=0;i<8;i++) {
      printf("%02x",(int)input[i]);
      printf("(%02x) ",(int)state[i]);
    }
    printf("\n");
  }
  return 0;
}


