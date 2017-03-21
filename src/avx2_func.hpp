
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
#include "immintrin.h"

namespace avx2_func{
	//
	//
	////////////////////////////////////////////////////////////////////////////////////////////
	//
	//
	template <int N>
	inline __m256i shift_right(__m256i A)
	{
		if     ( N ==  0 ) return A;
		else if( N <  16 ) return _mm256_alignr_epi8(_mm256_permute2x128_si256(A, A, _MM_SHUFFLE(2, 0, 0, 1)), A, (uint8_t)(N));
		else if( N == 16 ) return                    _mm256_permute2x128_si256(A, A, _MM_SHUFFLE(2, 0, 0, 1));
		else               return _mm256_srli_si256 (_mm256_permute2x128_si256(A, A, _MM_SHUFFLE(2, 0, 0, 1)), (uint8_t)(N - 16));
	}
	//
	//
	////////////////////////////////////////////////////////////////////////////////////////////
	//
	//
	template <int N>
	inline __m256i shift_left(__m256i A)
	{
		if     ( N ==  0 ) return A;
		else if( N <  16 ) return _mm256_alignr_epi8(A, _mm256_permute2x128_si256(A, A, _MM_SHUFFLE(0, 0, 2, 0)), (uint8_t)(16 - N));
		else if( N == 16 ) return                       _mm256_permute2x128_si256(A, A, _MM_SHUFFLE(0, 0, 2, 0));
		else               return _mm256_slli_si256 (   _mm256_permute2x128_si256(A, A, _MM_SHUFFLE(0, 0, 2, 0)), (uint8_t)(N - 16));
	}
	//
	//
	////////////////////////////////////////////////////////////////////////////////////////////
	//
	//
	template <int N>
	inline __m256i rotate_right(__m256i A)
	{
		if( N == 0 )       return A;
		else if( N  < 16 ) return (shift_right<N>(A) | shift_left<32 - N>(A));
		else if( N == 16 ) return  _mm256_permute2x128_si256(A, A, 0x01);
		else               return (shift_right<N>(A) | shift_left<32 - N>(A));
	}
	//
	//
	////////////////////////////////////////////////////////////////////////////////////////////
	//
	//
	template <int N>
	inline __m256i rotate_left(__m256i A)
	{
		if     ( N ==  0 ) return A;
		else if( N  < 16 ) return shift_right<32 - N>(A) | shift_left<N>(A);
		else if( N == 16 ) return  _mm256_permute2x128_si256(A, A, 0x01);
		else               return shift_right<32 - N>(A) | shift_left<N>(A);
	}
};
