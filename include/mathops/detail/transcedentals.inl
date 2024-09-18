#ifndef TRANSCEDENTALS_INL
#define TRANSCEDENTALS_INL

#include <mathops/transcedentals.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops/detail/SEQ/seq_transcedentals.hpp>

#include <cmath>

namespace mathops
{

#ifdef HAS_AVX

#define FAST_SQRT_ARR avx::fast_sqrt_arr

#else // HAS_AVX

#define FAST_SQRT_ARR seq::fast_sqrt_arr

#endif // HAS_AVX

    inline float sqrt(float num)
    {
        return std::sqrt(num);
    }

    inline float fast_sqrt(float num)
    {
        return 1 / fast_invsqrt(num);
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

    inline void fast_sqrt_arr(float *arr, size_t size)
    {
        //FAST_SQRT_ARR(arr, size); TODO
    }
}

#endif // TRANSCEDENTALS_INL