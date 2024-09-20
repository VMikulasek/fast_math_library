#ifndef TRANSCEDENTALS_INL
#define TRANSCEDENTALS_INL

#include <mathops/transcedentals.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops/detail/SEQ/seq_transcedentals.hpp>

#include <cmath>

#include <mathops/detail/common/memory_common.inl>

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
        return 1 / fast_invsqrt(num);
    }

    inline float invsqrt(float num)
    {
        return 1 / std::sqrt(num);
    }

    inline float fast_invsqrt(float num)
    {
        float numHalf = 0.5f * num;
        int i = *(int*)&num;
        i = 0x5f375a86- (i>>1);
        num = *(float*)&i;
        num = num * (1.5f - numHalf * num * num);
        return num;
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