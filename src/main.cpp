
/*
 *	Shift and Rotate intrinsics for AVX2 - Copyright (c) 2017 Bertrand LE GAL
 *
 *  This software is provided 'as-is', without any express or
 *  implied warranty. In no event will the authors be held
 *  liable for any damages arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute
 *  it freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented;
 *  you must not claim that you wrote the original software.
 *  If you use this software in a product, an acknowledgment
 *  in the product documentation would be appreciated but
 *  is not required.
 *
 *  2. Altered source versions must be plainly marked as such,
 *  and must not be misrepresented as being the original software.
 *
 *  3. This notice may not be removed or altered from any
 *  source distribution.
 *
 *  This source is based on the SHIFT functions presented:
 *  http://stackoverflow.com/questions/25248766/emulating-shifts-on-32-bytes-with-avx
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <cassert>

#include "avx2_func.hpp"

using namespace std;
using namespace avx2_func;

inline void uint8_t_show(const __m256i reg)
{
	uint8_t tmp[32];
	_mm256_storeu_si256 ( (__m256i *) tmp, reg);
	for(int i=0; i<32; i++)
		printf("%3d ", tmp[31-i]);
	printf("\n");
}

int main(int argc, char* argv[]) {

    __m256i r = _mm256_setr_epi8(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);

    printf("#\n");
    printf("########################################\n");
    printf("#\n");
    printf("Rotate Right 0 : "); uint8_t_show( rotate_right<0>( r ) );
    printf("Rotate Right 1 : "); uint8_t_show( rotate_right<1>( r ) );
    printf("Rotate Right 2 : "); uint8_t_show( rotate_right<2>( r ) );
    printf("Rotate Right 3 : "); uint8_t_show( rotate_right<3>( r ) );
    printf("Rotate Right 4 : "); uint8_t_show( rotate_right<4>( r ) );
    printf("Rotate Right 5 : "); uint8_t_show( rotate_right<5>( r ) );
    printf("Rotate Right 6 : "); uint8_t_show( rotate_right<6>( r ) );
    printf("Rotate Right 7 : "); uint8_t_show( rotate_right<7>( r ) );
    printf("Rotate Right 8 : "); uint8_t_show( rotate_right<8>( r ) );
    printf("Rotate Right 9 : "); uint8_t_show( rotate_right<9>( r ) );
    printf("Rotate Right 10: "); uint8_t_show( rotate_right<10>( r ) );
    printf("Rotate Right 11: "); uint8_t_show( rotate_right<11>( r ) );
    printf("Rotate Right 12: "); uint8_t_show( rotate_right<12>( r ) );
    printf("Rotate Right 13: "); uint8_t_show( rotate_right<13>( r ) );
    printf("Rotate Right 14: "); uint8_t_show( rotate_right<14>( r ) );
    printf("Rotate Right 15: "); uint8_t_show( rotate_right<15>( r ) );
    printf("Rotate Right 16: "); uint8_t_show( rotate_right<16>( r ) );
    printf("Rotate Right 17: "); uint8_t_show( rotate_right<17>( r ) );
    printf("Rotate Right 18: "); uint8_t_show( rotate_right<18>( r ) );
    printf("Rotate Right 19: "); uint8_t_show( rotate_right<19>( r ) );
    printf("Rotate Right 20: "); uint8_t_show( rotate_right<20>( r ) );
    printf("Rotate Right 21: "); uint8_t_show( rotate_right<21>( r ) );
    printf("Rotate Right 22: "); uint8_t_show( rotate_right<22>( r ) );
    printf("Rotate Right 23: "); uint8_t_show( rotate_right<23>( r ) );
    printf("Rotate Right 24: "); uint8_t_show( rotate_right<24>( r ) );
    printf("Rotate Right 25: "); uint8_t_show( rotate_right<25>( r ) );
    printf("Rotate Right 26: "); uint8_t_show( rotate_right<26>( r ) );
    printf("Rotate Right 27: "); uint8_t_show( rotate_right<27>( r ) );
    printf("Rotate Right 28: "); uint8_t_show( rotate_right<28>( r ) );
    printf("Rotate Right 29: "); uint8_t_show( rotate_right<29>( r ) );
    printf("Rotate Right 30: "); uint8_t_show( rotate_right<30>( r ) );
    printf("Rotate Right 31: "); uint8_t_show( rotate_right<31>( r ) );
    printf("#\n");
    printf("########################################\n");
    printf("#\n");
    printf("Rotate Left 0 : "); uint8_t_show( rotate_left<0>( r ) );
    printf("Rotate Left 1 : "); uint8_t_show( rotate_left<1>( r ) );
    printf("Rotate Left 2 : "); uint8_t_show( rotate_left<2>( r ) );
    printf("Rotate Left 3 : "); uint8_t_show( rotate_left<3>( r ) );
    printf("Rotate Left 4 : "); uint8_t_show( rotate_left<4>( r ) );
    printf("Rotate Left 5 : "); uint8_t_show( rotate_left<5>( r ) );
    printf("Rotate Left 6 : "); uint8_t_show( rotate_left<6>( r ) );
    printf("Rotate Left 7 : "); uint8_t_show( rotate_left<7>( r ) );
    printf("Rotate Left 8 : "); uint8_t_show( rotate_left<8>( r ) );
    printf("Rotate Left 9 : "); uint8_t_show( rotate_left<9>( r ) );
    printf("Rotate Left 10: "); uint8_t_show( rotate_left<10>( r ) );
    printf("Rotate Left 11: "); uint8_t_show( rotate_left<11>( r ) );
    printf("Rotate Left 12: "); uint8_t_show( rotate_left<12>( r ) );
    printf("Rotate Left 13: "); uint8_t_show( rotate_left<13>( r ) );
    printf("Rotate Left 14: "); uint8_t_show( rotate_left<14>( r ) );
    printf("Rotate Left 15: "); uint8_t_show( rotate_left<15>( r ) );
    printf("Rotate Left 16: "); uint8_t_show( rotate_left<16>( r ) );
    printf("Rotate Left 17: "); uint8_t_show( rotate_left<17>( r ) );
    printf("Rotate Left 18: "); uint8_t_show( rotate_left<18>( r ) );
    printf("Rotate Left 19: "); uint8_t_show( rotate_left<19>( r ) );
    printf("Rotate Left 20: "); uint8_t_show( rotate_left<20>( r ) );
    printf("Rotate Left 21: "); uint8_t_show( rotate_left<21>( r ) );
    printf("Rotate Left 22: "); uint8_t_show( rotate_left<22>( r ) );
    printf("Rotate Left 23: "); uint8_t_show( rotate_left<23>( r ) );
    printf("Rotate Left 24: "); uint8_t_show( rotate_left<24>( r ) );
    printf("Rotate Left 25: "); uint8_t_show( rotate_left<25>( r ) );
    printf("Rotate Left 26: "); uint8_t_show( rotate_left<26>( r ) );
    printf("Rotate Left 27: "); uint8_t_show( rotate_left<27>( r ) );
    printf("Rotate Left 28: "); uint8_t_show( rotate_left<28>( r ) );
    printf("Rotate Left 29: "); uint8_t_show( rotate_left<29>( r ) );
    printf("Rotate Left 30: "); uint8_t_show( rotate_left<30>( r ) );
    printf("Rotate Left 31: "); uint8_t_show( rotate_left<31>( r ) );
    printf("#\n");
    printf("########################################\n");
    printf("#\n");
    return 1;
}
