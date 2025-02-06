#ifndef SIMD_VEC_AVX_FLOAT_INL
#define SIMD_VEC_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec_avx_float.hpp>
#include <simd/simd_operations_avx.hpp>
#include <simd/simd_common.hpp>

#include <cmath>

namespace simd
{
namespace avx
{

#ifdef HAS_AVX

    template<size_t L>
    inline Vec<L, float> addvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2)
    {
        Vec<L, float> result;

        size_t i = 0;

        for(; i + AVX_FLOAT_VECTOR_SIZE < L; i += AVX_FLOAT_VECTOR_SIZE)
        {
            auto reg1 = SIMDOperations<float, AVX>::load_vector(&(vec1.data[i]));
            auto reg2 = SIMDOperations<float, AVX>::load_vector(&(vec2.data[i]));

            auto resReg = SIMDOperations<float, AVX>::add(reg1, reg2);

            SIMDOperations<float, AVX>::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] + vec2.data[i];
        }

        return result;
    }
    template<size_t L>
    inline Vec<L, float> subvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2)
    {
        Vec<L, float> result;

        size_t i = 0;

        for(; i + AVX_FLOAT_VECTOR_SIZE < L; i += AVX_FLOAT_VECTOR_SIZE)
        {
            auto reg1 = SIMDOperations<float, AVX>::load_vector(&(vec1.data[i]));
            auto reg2 = SIMDOperations<float, AVX>::load_vector(&(vec2.data[i]));

            auto resReg = SIMDOperations<float, AVX>::sub(reg1, reg2);

            SIMDOperations<float, AVX>::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] - vec2.data[i];
        }

        return result;
    }
    template<size_t L>
    inline Vec<L, float> mulvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2)
    {
        Vec<L, float> result;

        size_t i = 0;

        for(; i + AVX_FLOAT_VECTOR_SIZE < L; i += AVX_FLOAT_VECTOR_SIZE)
        {
            auto reg1 = SIMDOperations<float, AVX>::load_vector(&(vec1.data[i]));
            auto reg2 = SIMDOperations<float, AVX>::load_vector(&(vec2.data[i]));

            auto resReg = SIMDOperations<float, AVX>::mul(reg1, reg2);

            SIMDOperations<float, AVX>::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] * vec2.data[i];
        }
        
        return result;
    }
    template<size_t L>
    inline Vec<L, float> divvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2)
    {
        Vec<L, float> result;

        size_t i = 0;

        for(; i + AVX_FLOAT_VECTOR_SIZE < L; i += AVX_FLOAT_VECTOR_SIZE)
        {
            auto reg1 = SIMDOperations<float, AVX>::load_vector(&(vec1.data[i]));
            auto reg2 = SIMDOperations<float, AVX>::load_vector(&(vec2.data[i]));

            auto resReg = SIMDOperations<float, AVX>::div(reg1, reg2);

            SIMDOperations<float, AVX>::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = vec1.data[i] / vec2.data[i];
        }
        
        return result;
    }

    template<size_t L>
    inline Vec<L, float> absvf(const Vec<L, float> &vec)
    {
        Vec<L, float> result;

        size_t i = 0;

        for(; i + AVX_FLOAT_VECTOR_SIZE < L; i += AVX_FLOAT_VECTOR_SIZE)
        {
            auto reg = SIMDOperations<float, AVX>::load_vector(&(vec.data[i]));

            auto resReg = SIMDOperations<float, AVX>::abs(reg);

            SIMDOperations<float, AVX>::materialize_register(resReg, &(result.data[i]));
        }

        for (; i < L; i++)
        {
            result.data[i] = std::abs(vec.data[i]);
        }
        
        return result;
    }

    template<size_t L>
    inline float dotvf(const Vec<L, float> &vec1, const Vec<L, float> &vec2)
    {
        float result = 0;

        size_t i = 0;

        for(; i + AVX_FLOAT_VECTOR_SIZE < L; i += AVX_FLOAT_VECTOR_SIZE)
        {
            auto reg1 = SIMDOperations<float, AVX>::load_vector(&(vec1.data[i]));
            auto reg2 = SIMDOperations<float, AVX>::load_vector(&(vec2.data[i]));

            auto tmpResReg = SIMDOperations<float, AVX>::mul(reg1, reg2);
            auto zeroReg = SIMDOperations<float, AVX>::set_register_zero();
            tmpResReg = SIMDOperations<float, AVX>::horizontal_add(tmpResReg, zeroReg);
            tmpResReg = SIMDOperations<float, AVX>::horizontal_add(tmpResReg, zeroReg);

            alignas(AVX_ALIGNMENT) float tmpRes[AVX_FLOAT_VECTOR_SIZE];
            SIMDOperations<float, AVX>::materialize_register(tmpResReg, tmpRes);

            result += tmpRes[0] + tmpRes[4];
        }

        for (; i < L; i++)
        {
            result += vec1.data[i] * vec2.data[i];
        }

        return result;
    }

#endif // HAS_AVX

} // namespace avx
} // namespace simd

#endif // SIMD_VEC_AVX_FLOAT_INL