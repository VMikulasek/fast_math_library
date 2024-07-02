#ifndef SIMD_OPERATIONS_AVX_FLOAT_INL
#define SIMD_OPERATIONS_AVX_FLOAT_INL

#include "../../../include/simd/simd_common.hpp"
#include "./simd_operations_avx_float.hpp"
#include "../vector/simd_vector_avx_float.hpp"

namespace simd
{
    inline void SIMDOperations<float, InstructionSet::AVX>::load_op1(
        SIMDVector<NumType, INS_SET> &vector)
    {
        op1Reg = _mm256_load_ps(vector.get_content());
    }

    inline void SIMDOperations<float, InstructionSet::AVX>::load_op2(
        SIMDVector<NumType, INS_SET> &vector)
    {
        op2Reg = _mm256_load_ps(vector.get_content());
    }

    inline void SIMDOperations<float, InstructionSet::AVX>::load_ops(
        SIMDVector<NumType, INS_SET> &vector1,
        SIMDVector<NumType, INS_SET> &vector2)
    {
        op1Reg = _mm256_load_ps(vector1.get_content());
        op2Reg = _mm256_load_ps(vector2.get_content());
    }

    inline SIMDVector<float, InstructionSet::AVX> SIMDOperations<float, InstructionSet::AVX>::get_result()
    {
        SIMDVector<NumType, INS_SET> result;
        _mm256_store_ps(result.vector, resultReg);
        return result;
    }
}

#endif // SIMD_OPERATIONS_AVX_FLOAT_INL