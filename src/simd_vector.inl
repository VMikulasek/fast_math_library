#ifndef SIMD_VECTOR_INL
#define SIMD_VECTOR_INL

#include "../include/simd_common.hpp"
#include "../include/simd_vector.hpp"

#include <vector>
#include <cstring>

namespace simd
{
    inline SIMDVector<float, InstructionSet::AVX>::SIMDVector(
        float n1, float n2, float n3, float n4, float n5,
        float n6, float n7, float n8)
        : vector{ n1, n2, n3, n4, n5, n6, n7, n8 }{};

    inline SIMDVector<float, InstructionSet::AVX>::SIMDVector(
        std::vector<float> vec)
    {
        if (vec.size() != VECTOR_SIZE)
        {
            // throw invalid vector size exception
        }

        std::memcpy(vector, vec.data(), VECTOR_SIZE * sizeof(float));
    }
}

#endif SIMD_VECTOR_INL