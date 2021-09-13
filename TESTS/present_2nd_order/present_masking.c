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

uint8_t T[16][16] = {{0xc, 0xc, 0x2, 0x2, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0x6, 0x6, 0x8, 0x8, 0xc, 0xc},
                     {0x9, 0x9, 0x7, 0x7, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x3, 0x3, 0xd, 0xd, 0x9, 0x9},
                     {0xe, 0xe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xa, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4},
                     {0xb, 0xb, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0xf, 0xf, 0x5, 0x5, 0x5, 0x5, 0x1, 0x1},
                     {0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0x4, 0x4, 0xe, 0xe, 0xa, 0xa, 0xa, 0xa, 0x0, 0x0},
                     {0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0x1, 0x1, 0xb, 0xb, 0xf, 0xf, 0xf, 0xf, 0x5, 0x5},
                     {0x8, 0x8, 0x8, 0x8, 0x6, 0x6, 0x8, 0x8, 0x8, 0x8, 0xc, 0xc, 0x2, 0x2, 0x8, 0x8},
                     {0xd, 0xd, 0xd, 0xd, 0x3, 0x3, 0xd, 0xd, 0xd, 0xd, 0x9, 0x9, 0x7, 0x7, 0xd, 0xd},
                     {0x6, 0x6, 0xc, 0xc, 0x2, 0x2, 0x6, 0x6, 0x6, 0x6, 0x8, 0x8, 0x6, 0x6, 0x6, 0x6},
                     {0x3, 0x3, 0x9, 0x9, 0x7, 0x7, 0x3, 0x3, 0x3, 0x3, 0xd, 0xd, 0x3, 0x3, 0x3, 0x3},
                     {0x4, 0x4, 0xe, 0xe, 0xe, 0xe, 0xa, 0xa, 0x0, 0x0, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe},
                     {0x1, 0x1, 0xb, 0xb, 0xb, 0xb, 0xf, 0xf, 0x5, 0x5, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb},
                     {0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0xe, 0xe, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0xa, 0xa},
                     {0x5, 0x5, 0x1, 0x1, 0x1, 0x1, 0xb, 0xb, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xf, 0xf},
                     {0x2, 0x2, 0x6, 0x6, 0x8, 0x8, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0xc, 0xc, 0x2, 0x2},
                     {0x7, 0x7, 0x3, 0x3, 0xd, 0xd, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x9, 0x9, 0x7, 0x7}};

uint8_t A[16] = {0x8, 0xF, 0xD, 0xA, 0xC, 0xB, 0x9, 0xE, 0x4, 0x3, 0x1, 0x6, 0x0, 0x7, 0x5, 0x2};

uint8_t P[64] = {0, 16, 32, 48, 1, 17, 33, 49, 2, 18, 34, 50, 3, 19, 35, 51,
                 4, 20, 36, 52, 5, 21, 37, 53, 6, 22, 38, 54, 7, 23, 39, 55, 
                 8, 24, 40, 56, 9, 25, 41, 57, 10, 26, 42, 58, 11, 27, 43, 59,
                 12, 28, 44, 60, 13, 29, 45, 61, 14, 30, 46, 62, 15, 31, 47, 63};
#define FOR_UNROLL(_i) \
  state[0][_i] = A[temp_state[0][_i]]; \
  state[1][_i] = A[temp_state[1][_i]]; \
  state[2][_i] = A[temp_state[2][_i]]; 

#define FOR_UNROLL_2(_i) \
  state[0][P[_i] >> 2] |= ((temp_state[0][_i >> 2] >> (_i % 4)) & 0x1) << (P[_i] % 4); \
  state[1][P[_i] >> 2] |= ((temp_state[1][_i >> 2] >> (_i % 4)) & 0x1) << (P[_i] % 4); \
  state[2][P[_i] >> 2] |= ((temp_state[2][_i >> 2] >> (_i % 4)) & 0x1) << (P[_i] % 4);

#define FOR_UNROLL_TT(_i) \
  temp_state[2][_i] = (*TT)[state[0][_i]][state[1][_i]]; \
  temp_state[1][_i] = (*TT)[state[2][_i]][state[0][_i]]; \
  temp_state[0][_i] = (*TT)[state[1][_i]][state[2][_i]];

#define FOR_UNROLL_T(_i) \
  temp_state[2][_i] = T[state[0][_i]][state[1][_i]]; \
  temp_state[1][_i] = T[state[2][_i]][state[0][_i]]; \
  temp_state[0][_i] = T[state[1][_i]][state[2][_i]];


void present_round(uint8_t state[3][16], uint8_t key[3][16]) {
  uint8_t temp_state[3][16];

  int i;
  // Add round key
  for(i=0;i<16;i++) {
    state[0][i] ^= key[0][i];
    state[1][i] ^= key[1][i];
    state[2][i] ^= key[2][i];
  }
  uint8_t (*TT)[16][16];
  TT = &T;
  starttrigger();
#ifndef PRESENT_TEST
  asm volatile (
      "movs %0, %1\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      :"=r"(TT)
      :"r"(T)
      :
      );
#endif
  FOR_UNROLL_TT(0);
  FOR_UNROLL_TT(1);
  FOR_UNROLL_TT(2);
  FOR_UNROLL_TT(3);
#ifndef PRESENT_TEST
  asm volatile (
      "push {r7}\n"
      "pop {r7}\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      "movs r7, r7\n"
      :
      );
#endif
  endtrigger();

  FOR_UNROLL_T(4);
  FOR_UNROLL_T(5);
  FOR_UNROLL_T(6);
  FOR_UNROLL_T(7);
  FOR_UNROLL_T(8);
  FOR_UNROLL_T(9);
  FOR_UNROLL_T(10);
  FOR_UNROLL_T(11);
  FOR_UNROLL_T(12);
  FOR_UNROLL_T(13);
  FOR_UNROLL_T(14);
  FOR_UNROLL_T(15);

  // Sbox
  //for(i=0;i<16;i++) {
  //  temp_state[2][i] = T[state[0][i]][state[1][i]];
  //  temp_state[1][i] = T[state[2][i]][state[0][i]];
  //  temp_state[0][i] = T[state[1][i]][state[2][i]];
  //}

  //FOR_UNROLL(0);
  //FOR_UNROLL(1);
  //FOR_UNROLL(2);
  //FOR_UNROLL(3);
  //FOR_UNROLL(4);
  //FOR_UNROLL(5);
  //FOR_UNROLL(6);
  //FOR_UNROLL(7);
  //FOR_UNROLL(8);
  //FOR_UNROLL(9);
  //FOR_UNROLL(10);
  //FOR_UNROLL(11);
  //FOR_UNROLL(12);
  //FOR_UNROLL(13);
  //FOR_UNROLL(14);
  //FOR_UNROLL(15);
  for(i=0;i<16;i++) {
      state[0][i] = A[temp_state[0][i]];
      state[1][i] = A[temp_state[1][i]];
      state[2][i] = A[temp_state[2][i]];
  }
  for(i=0;i<16;i++) {
    temp_state[2][i] = T[state[0][i]][state[1][i]];
    temp_state[1][i] = T[state[2][i]][state[0][i]];
    temp_state[0][i] = T[state[1][i]][state[2][i]];
  }

  // Permute
  for(i=0;i<16;i++) {
    state[0][i] = 0;
    state[1][i] = 0;
    state[2][i] = 0;
  }
  for(i=0;i<64;i++) {
    state[0][P[i] >> 2] |= ((temp_state[0][i >> 2] >> (i % 4)) & 0x1) << (P[i] % 4);
    state[1][P[i] >> 2] |= ((temp_state[1][i >> 2] >> (i % 4)) & 0x1) << (P[i] % 4);
    state[2][P[i] >> 2] |= ((temp_state[2][i >> 2] >> (i % 4)) & 0x1) << (P[i] % 4);
  }
  /*FOR_UNROLL_2(60);
  FOR_UNROLL_2(61);
  FOR_UNROLL_2(62);
  FOR_UNROLL_2(63);*/
}

void share(uint8_t shares[3][16], uint8_t val[8], uint8_t* masks) {
  int i,j;
  for(i=0;i<8;i++) {
    shares[0][i*2] = val[i] & 0xF;
    shares[0][i*2+1] = (val[i] >> 4);
  }
  for(i=0;i<16;i++) {
    readrandombyte(&shares[1][i]);
    readrandombyte(&shares[2][i]);

    masks[i] = shares[1][i];
    masks[i+16] = shares[2][i];

    shares[1][i] &= 0x0F;
    shares[2][i] &= 0x0F;
    shares[0][i] ^= shares[1][i] ^ shares[2][i];
    //shares[1][i] = 0;
    //shares[2][i] = 0;
  }
}

void unshare(uint8_t val[8], uint8_t shares[3][16]) {
  int i;
  for(i=0;i<8;i++) {
    val[i] = shares[0][i*2] ^ shares[1][i*2] ^ shares[2][i*2];
    val[i] |= (shares[0][i*2+1] ^ shares[1][i*2+1] ^ shares[2][i*2+1]) << 4;
  }
}

//void test_round() {
//  uint8_t pt[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t key[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t ct[8];
//
//  uint8_t state_share[3][16];
//  uint8_t key_share[3][16];
//
//  share(state_share, pt);
//  share(key_share, key);
//
//  present_round(state_share, key_share);
//
//  unshare(ct, state_share);
//  for(int i=0;i<8;i++) {
//    printf("%x, ", ct[i]);
//  }
//  printf("\n");
//}
//
//
//int main() {
//  test_round();
//  return 0;
//}
