#ifndef SIMD_VECTOR_AVX_FLOAT_INL
#define SIMD_VECTOR_AVX_FLOAT_INL

#include "../../simd_common.hpp"
#include "simd_vector_avx_float.hpp"

#include <vector>
#include <cstring>
#include <stdexcept>

namespace simd
{
    inline SIMDVector<float, InstructionSet::AVX>::SIMDVector(
        NumType n1, NumType n2, NumType n3, NumType n4, NumType n5,
        NumType n6, NumType n7, NumType n8)
        : vector{ n1, n2, n3, n4, n5, n6, n7, n8 }{};

    inline SIMDVector<float, InstructionSet::AVX>::SIMDVector(
        std::vector<NumType> &vec)
    {
        if (vec.size() != VECTOR_SIZE)
        {
            throw std::invalid_argument(std::string(__func__) + ": invalid vector size");
        }

        std::memcpy(vector, vec.data(), VECTOR_SIZE * sizeof(float));
    }

    inline const float *SIMDVector<float, InstructionSet::AVX>::get_content()
    {
        return this->vector;
    }
}

#endif // SIMD_VECTOR_AVX_FLOAT_INL