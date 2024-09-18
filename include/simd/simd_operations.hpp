#ifndef SIMD_OPERATIONS_HPP
#define SIMD_OPERATIONS_HPP

#ifdef HAS_AVX
#include <simd/simd_operations_avx.hpp>
#endif
#ifdef HAS_AVX2
#include <simd/simd_operations_avx2.hpp>
#endif

#endif // SIMD_OPERATIONS_HPP