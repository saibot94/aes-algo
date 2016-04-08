#include <iostream>
#include <cstdio>
using namespace std;

#ifndef uint32
#define uint32 unsigned long
#endif
#ifndef uint8
#define uint8 unsigned char
#endif

uint32 RotWord(uint32 T)
{
	// return uint32 rotated
	return (uint32)((T << 8) | (T >> 24));
}

uint8 dot(uint8 aa, uint8 bb)
{
	// returneaza rezultatul operatiei aa * bb ( * - operatia dot)
   uint8 p = 0;
   uint8 counter;
   uint8 hi_bit_set;
   for (counter = 0; counter < 8; counter++) {
      if ((bb & 1) != 0) {
         p ^= aa;
      }
      hi_bit_set = (uint8) (aa & 0x80);
      aa <<= 1;
      if (hi_bit_set != 0) {
         aa ^= 0x1b; /* x^8 + x^4 + x^3 + x + 1 */
      }
      bb >>= 1;
   }
   return p;
}


int main() {
   // just some tests
	uint32 myvar = (uint32)0xcf123456;
	uint8 dotval = dot(0x57, 0x83);
	
	printf("%04lX\n", RotWord(myvar));
	printf("%02X\n", dotval);
	return 0;
}