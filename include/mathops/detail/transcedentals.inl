#ifndef TRANSCEDENTALS_INL
#define TRANSCEDENTALS_INL

#include <mathops/transcedentals.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops/detail/SEQ/seq_transcedentals.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_common.hpp>

#include <cmath>

namespace mathops
{

#if defined(HAS_AVX) && defined(HAS_AVX2)

#define FAST_SQRT_ARR avx::fast_sqrt_arr
#define FAST_INVSQRT_ARR avx::fast_invsqrt_arr

#else // HAS_AVX

#define FAST_SQRT_ARR seq::fast_sqrt_arr
#define FAST_INVSQRT_ARR seq::fast_invsqrt_arr

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

    // source swiftshader
    inline float _sin5q(float x)
    {
        constexpr float A = 6.28230858f;
        constexpr float B = -41.1693687f;
        constexpr float C = 74.4388885f;
        float x2 = x * x;
        return x * (A + x2 * (B + x2 * C));
    }
    inline float fast_sin(float num)
    {
        constexpr float pi2 = 1 / (2 * 3.1415926535f);
        float x_2 = 0.25f - num * pi2;
        float z = 0.25f - abs(x_2 - round(x_2));
        return _sin5q(z);
    }
    inline float fast_cos(float num)
    {
        constexpr float pi2 = 1 / (2 * 3.1415926535f);
        float x_2 = num * pi2;
        float z = 0.25f - abs(x_2 - round(x_2));
        return _sin5q(z);
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
}

#endif // TRANSCEDENTALS_INL