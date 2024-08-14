#ifndef SIMD_OPERATIONS_AVX_FLOAT_INL
#define SIMD_OPERATIONS_AVX_FLOAT_INL

#include <simd/simd_common.hpp>
#include <simd/detail/operations/simd_operations_avx_float.hpp>

#include <cstdlib>

namespace simd
{
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::load_vector(
        const float *arr)
    {
        return _mm256_load_ps(arr);
    }

    inline float *SIMDOperations<float, InstructionSet::AVX>::materialize_register(
        AvxReg &reg)
    {
        float *result = static_cast<float *>(std::aligned_alloc(32, AVX_FLOAT_VECTOR_SIZE * sizeof(float)));
        _mm256_store_ps(result, reg);
        return result;
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::add(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_add_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::sub(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_sub_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::mul(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_mul_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::div(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_div_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_and(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_and_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_or(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_or_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_xor(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_xor_ps(vec1, vec2);
    }

    template<AvxCmpVariant Variant>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::cmp(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_cmp_ps(vec1, vec2, static_cast<int>(Variant));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::horizontal_add(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_hadd_ps(vec1, vec2);
    }
}

#endif // SIMD_OPERATIONS_AVX_FLOAT_INL