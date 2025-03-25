#ifndef SIMD_OPERATIONS_AVX2_INT_INL
#define SIMD_OPERATIONS_AVX2_INT_INL

#include <simd/detail/operations/simd_operations_avx2_int.hpp>

namespace simd
{
    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::load_vector(
        const int *arr)
    {
        return _mm256_load_si256(reinterpret_cast<const Reg *>(arr));
    }

    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::set_register_zero()
    {
        return _mm256_setzero_si256();
    }

    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::set_register(
        int num)
    {
        return _mm256_set1_epi32(num);
    }

    inline void SIMDOperations<int, InstructionSet::AVX2>::materialize_register(
        const Reg &reg, int *dst)
    {
        _mm256_store_si256(reinterpret_cast<Reg *>(dst), reg);
    }

    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::add(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_add_epi32(vec1, vec2);
    }

    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::sub(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_sub_epi32(vec1, vec2);
    }

    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::shift_left(
        const Reg &vec, int count)
    {
        return _mm256_slli_epi32(vec, count);
    }

    inline SIMDOperations<int, InstructionSet::AVX2>::Reg SIMDOperations<int, InstructionSet::AVX2>::shift_right(
        const Reg &vec, int count)
    {
        return _mm256_srli_epi32(vec, count);
    }
} // namespace simd

#endif // SIMD_OPERATIONS_AVX2_INT_INL