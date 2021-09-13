#include <stdint.h>

uint32_t ui32randval = 0;
uint8_t ui8randval = 0;
uint8_t mask[16] = {};
#ifdef TEST
#endif

#include "../elmoasmfunctionsdef.h"


/* these masked data functions use ELMO's randbyte() to get better 
 * quality uniform random numbers
 * 
 */
void maskdata(uint8_t*  data)
{
	int i=0;
	for (;i<16;i++)
	{
		uint8_t rr;
		randbyte(&rr);
		mask[i] = rr;
		data[i] ^= rr;
	}
}

void unmaskdata(uint8_t* data)
{
	int i=0;
        for (;i<16;i++)
        {
            data[i] ^= mask[i];
        }
}

void setseed(int newseed)
{
	ui32randval = 0;
}

void runrand()
{
	uint8_t *rr=(uint8_t*)&ui32randval;
	randbyte(&rr[0]);
	randbyte(&rr[2]);
	randbyte(&rr[1]);
	randbyte(&rr[3]);
#ifdef __arm__
	asm("mov r7, %[value]" 
		:
		: [value] "r" (ui32randval));
#endif
	randbyte(&ui8randval);

}
void readrandombyte(unsigned char* byte)
{
    randbyte(byte);
}
uint32_t getrandui32()
{
	return ui32randval;
}

uint8_t getrandui8()
{
    return ui8randval;
}
