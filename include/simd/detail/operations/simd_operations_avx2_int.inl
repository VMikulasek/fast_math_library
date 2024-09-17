#ifndef SIMD_OPERATIONS_AVX2_INT_INL
#define SIMD_OPERATIONS_AVX2_INT_INL

#include <simd/detail/operations/simd_operations_avx2_int.hpp>

namespace simd
{
    inline SIMDOperations<int, InstructionSet::AVX2>::Avx2IReg SIMDOperations<int, InstructionSet::AVX2>::load_vector(
        const int *arr)
    {
        return _mm256_load_si256(reinterpret_cast<const __m256i *>(arr));
    }
} // namespace simd

#endif // SIMD_OPERATIONS_AVX2_INT_INL