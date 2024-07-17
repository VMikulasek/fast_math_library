#ifndef SIMD_OPERATIONS_AVX_FLOAT_INL
#define SIMD_OPERATIONS_AVX_FLOAT_INL

#include "../../simd_common.hpp"
#include "./simd_operations_avx_float.hpp"
#include "../vector/simd_vector_avx_float.hpp"

namespace simd
{
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::load_vector(
        SIMDVector<NumType, INS_SET> &vector)
    {
        return _mm256_load_ps(vector.get_content());
    }

    inline SIMDVector<float, InstructionSet::AVX> SIMDOperations<float, InstructionSet::AVX>::materialize_register(
        AvxReg &reg)
    {
        SIMDVector<NumType, INS_SET> result;
        _mm256_store_ps(result.vector, reg);
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

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::cmp(
        AvxReg &vec1, AvxReg &vec2, AvxCmpVariant variant)
    {
        return _mm256_cmp_ps(vec1, vec2, static_cast<int>(variant));
    }
}

#endif // SIMD_OPERATIONS_AVX_FLOAT_INL