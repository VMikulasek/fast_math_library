#ifndef SIMD_OPERATIONS_INL
#define SIMD_OPERATIONS_INL

#include "../include/simd_common.hpp"
#include "../include/simd_vector.hpp"
#include "../include/simd_operations.hpp"

namespace simd
{
    void SIMDOperations<float, InstructionSet::AVX>::load_op1(
        SIMDVector<float, InstructionSet::AVX> vector)
    {
        op1 = _mm256_load_ps(vector.get_content());
    }

    void SIMDOperations<float, InstructionSet::AVX>::load_op2(
        SIMDVector<float, InstructionSet::AVX> vector)
    {
        op2 = _mm256_load_ps(vector.get_content());
    }

    void SIMDOperations<float, InstructionSet::AVX>::load_ops(
        SIMDVector<float, InstructionSet::AVX> vector1,
        SIMDVector<float, InstructionSet::AVX> vector2)
    {
        op1 = _mm256_load_ps(vector1.get_content());
        op2 = _mm256_load_ps(vector2.get_content());
    }
}

#endif // SIMD_OPERATIONS_INL