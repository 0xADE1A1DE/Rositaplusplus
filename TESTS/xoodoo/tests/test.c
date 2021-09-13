#include "../Xoodoo.h"
#include <stdio.h>
#include <stdint.h>

extern uint32_t XoodooMask[12];                                                                                                                                      
void Absorb_Block(uint32_t *state, uint32_t *block)                                                                                   
{                                                                                                                                     
  int i;                                                                                                                              
  for(i=0;i<4;i++) {                                                                                                                  
    state[i] ^= block[i];                                                                                                             
  }                                                                                                                                   
}                                                                                                                                     
                                                                                                                                      
void Init_State(uint32_t *state)                                                                                                      
{                                                                                                                                     
  state[0] = 0xa144f6af;                                                                                                              
  state[1] = 0x0a09bef3;                                                                                                              
  state[2] = 0xf69b27da;                                                                                                              
  state[3] = 0xebf1aa2f;                                                                                                              
  state[4] = 0x79ec427d;                                                                                                              
  state[5] = 0x394b82c3;                                                                                                              
  state[6] = 0x15d52030;                                                                                                              
  state[7] = 0xe3d85ac4;                                                                                                              
  state[8] = 0x661b20a0;                                                                                                              
  state[9] = 0x01fc8349;                                                                                                              
  state[10] = 0x76868f25;                                                                                                             
  state[11] = 0x98fcda2a;                                                                                                             
}                                                                                                                                     
void SetMask()
{
  for (int i=0;i<12;i++)
  {
    XoodooMask[i] = 0;
  }
}
uint8_t conv(char* plaint)
{
  char buf[3];

  buf[0] = plaint[0];
  buf[1] = plaint[1];
  buf[2] = '\0';
  uint32_t byte=0;
  sscanf(buf, "%x", &byte);
  return byte;
}
int main()
{
  uint32_t state[12];
  char plaintinp[32];
  uint32_t plaint[4];
  SetMask();
  Init_State(state);
  printf("init state\n");
  for (int i=0;i<48;i++)
  {
    printf("%02x",((uint8_t*)state)[i]);
  }

  int ret = scanf("%32s",plaintinp);
  for (int i=0;i<16;i++)
  {
    ((uint8_t*)plaint)[i] = conv(&plaintinp[i*2]);
  }
  Absorb_Block(state, plaint);
  Xoodoo_Permute_12rounds(state, XoodooMask);
  
  for (int i=0;i<48;i++)
  {
    if ((i%4)==0)
    {
      printf(" ");
    }
    printf("%02x",((uint8_t*)state)[i]);
  }
  printf("\n");
  return 0;
}
