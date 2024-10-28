#ifndef TRANSCEDENTALS_INL
#define TRANSCEDENTALS_INL

#include <mathops/transcedentals.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops/detail/SEQ/seq_transcedentals.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_common.hpp>

#include <cmath>
#include <numbers>
#include <stdexcept>

namespace mathops
{

#if defined(HAS_AVX) && defined(HAS_AVX2)

#define FAST_SQRT_ARR avx::fast_sqrt_arr
#define FAST_INVSQRT_ARR avx::fast_invsqrt_arr

#define FAST_SIN_ARR avx::fast_sin_arr
#define FAST_COS_ARR avx::fast_cos_arr

#else // HAS_AVX

#define FAST_SQRT_ARR seq::fast_sqrt_arr
#define FAST_INVSQRT_ARR seq::fast_invsqrt_arr

#define FAST_SIN_ARR seq::fast_sin_arr
#define FAST_COS_ARR seq::fast_cos_arr

#endif // HAS_AVX

    inline float sqrt(float num)
    {
        return std::sqrt(num);
    }

    inline float fast_sqrt(float num)
    {
        if (num < 0)
        {
            return NAN;
        }

        num = fast_invsqrt(num);
        return 1 / num;
    }

    inline float invsqrt(float num)
    {
        return 1 / std::sqrt(num);
    }

    inline float fast_invsqrt(float num)
    {
        if (num < 0)
        {
            return NAN;
        }
        else if (num == 0)
        {
            return INFINITY;
        }
        
        float numHalf = 0.5f * num;
        int i = *(int *)&num;
        i = 0x5f375a86 - (i >> 1);
        num = *(float *)&i;
        num = num * (1.5f - numHalf * num * num);
        return num;
    }

    inline float sin(float num)
    {
        return std::sin(num);
    }
    inline float cos(float num)
    {
        return std::cos(num);
    }
    inline float tan(float num)
    {
        double cos_x = std::cos(num);
        if (cos_x == 0.0) {
            throw std::domain_error("tan(x) is undefined for x = k * pi (where k is an integer)");
        }
        return std::sin(num) / cos_x;
    }
    inline float cot(float num)
    {
        double sin_x = std::sin(num);
        if (sin_x == 0.0) {
            throw std::domain_error("cot(x) is undefined for x = k * pi (where k is an integer)");
        }
        return std::cos(num) / sin_x;
    }

    // source swiftshader
    inline float _sin5q(float x)
    {
        float x2 = x * x;
        return x * (A + x2 * (B + x2 * C));
    }
    inline float _calculateZ(float x_2)
    {
        return 0.25f - abs(x_2 - round(x_2));
    }
    inline float fast_sin(float num)
    {
        float x_2 = 0.25f - num * pi2;
        float z = _calculateZ(x_2);
        return _sin5q(z);
    }
    inline float fast_cos(float num)
    {
        float x_2 = num * pi2;
        float z = _calculateZ(x_2);
        return _sin5q(z);
    }
    inline float fast_tan(float num)
    {
        float x_2Cos = num * pi2;
        float x_2Sin = 0.25f - x_2Cos;
        float zSin = _calculateZ(x_2Sin);
        float zCos = _calculateZ(x_2Cos);
        return _sin5q(zSin) / _sin5q(zCos);
    }
    inline float fast_cot(float num)
    {
        float x_2Cos = num * pi2;
        float x_2Sin = 0.25f - x_2Cos;
        float zSin = _calculateZ(x_2Sin);
        float zCos = _calculateZ(x_2Cos);
        return _sin5q(zCos) / _sin5q(zSin);
    }

    inline float *fast_sqrt_arr(const float *arr, size_t size)
    {
        float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);
        if (dst == nullptr)
        {
            return nullptr;
        }

        FAST_SQRT_ARR(arr, size, dst);

        return dst;
    }

    inline float *fast_sqrt_arr(const std::vector<float> &arr)
    {
        return fast_sqrt_arr(arr.data(), arr.size());
    }

    inline float *fast_invsqrt_arr(const float *arr, size_t size)
    {
        float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);
        if (dst == nullptr)
        {
            return nullptr;
        }

        FAST_INVSQRT_ARR(arr, size, dst);

        return dst;
    }

    inline float *fast_invsqrt_arr(const std::vector<float> &arr)
    {
        return fast_invsqrt_arr(arr.data(), arr.size());
    }

    inline float *fast_sin_arr(const float *arr, size_t size)
    {
        float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);
        if (dst == nullptr)
        {
            return nullptr;
        }

        FAST_SIN_ARR(arr, size, dst);

        return dst;
    }

    inline float *fast_sin_arr(const std::vector<float> &arr)
    {
        return fast_sin_arr(arr.data(), arr.size());
    }


    inline float *fast_cos_arr(const float *arr, size_t size)
    {
        float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);
        if (dst == nullptr)
        {
            return nullptr;
        }

        FAST_COS_ARR(arr, size, dst);

        return dst;
    }

    inline float *fast_cos_arr(const std::vector<float> &arr)
    {
        return fast_cos_arr(arr.data(), arr.size());
    }
}

#endif // TRANSCEDENTALS_INL