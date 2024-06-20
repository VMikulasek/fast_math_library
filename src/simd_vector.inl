#ifndef SIMD_VECTOR_INL
#define SIMD_VECTOR_INL

#include "../include/simd_common.hpp"
#include "../include/simd_vector.hpp"

#include <vector>
#include <cstring>

namespace simd
{
    inline SIMDVector<float, InstructionSet::AVX>::SIMDVector(
        float op1, float op2, float op3, float op4, float op5,
        float op6, float op7, float op8)
        : vector{ op1, op2, op3, op4, op5, op6, op7, op8 }{};

    inline SIMDVector<float, InstructionSet::AVX>::SIMDVector(
        std::vector<float> vec)
    {
        if (vec.size() != VECTOR_SIZE)
        {
            // throw invalid vector size exception
        }

        std::memcpy(vector, vec.data(), VECTOR_SIZE);
    }
}

#endif SIMD_VECTOR_INL