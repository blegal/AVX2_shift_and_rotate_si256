# Introduction

This project delivers shift and rotate functions written in AVX2. They should
correspond to:

- _mm256_slli_si256
- _mm256_srli_si256
- _mm256_roli_si256
- _mm256_rori_si256

# Building

Just run `make` and expect the binary to be created in `bin/main`.

# Acknowledgment

This C++11 source code was written after the reading of

http://stackoverflow.com/questions/25248766/emulating-shifts-on-32-bytes-with-avx

that details the shift processing.
