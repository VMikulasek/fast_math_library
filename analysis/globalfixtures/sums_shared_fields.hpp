#ifndef SUMS_SHARED_FIELDS_HPP
#define SUMS_SHARED_FIELDS_HPP

#include <simd/simd_common.hpp>

#include <cstddef>
#include <cstdlib>      // std::aligned_alloc
#include <algorithm>    // std::fill

#if defined(_MSC_VER)
#include <malloc.h> // _aligned_malloc
#endif // _MSC_VER

namespace analysis
{
    static const size_t _1_ELEM_ARR_SIZE = 1;
    static const size_t _8_ELEM_ARR_SIZE = 8;
    static const size_t _9_ELEM_ARR_SIZE = 9;
    static const size_t _16_ELEM_ARR_SIZE = 16;
    static const size_t _17_ELEM_ARR_SIZE = 17;
    static const size_t _24_ELEM_ARR_SIZE = 24;
    static const size_t _25_ELEM_ARR_SIZE = 25;
    static const size_t BIG_ARR_SIZE = 15000000;

    alignas(AVX_ALIGNMENT) static const float _1ElemArr[_1_ELEM_ARR_SIZE]
        { 2 };
    alignas(AVX_ALIGNMENT) static const float _8ElemArr[_8_ELEM_ARR_SIZE]
        { 2, 1, 2.3, 1.3, 1.424, 13, 51341, 132413.1321 };
    alignas(AVX_ALIGNMENT) static const float _9ElemArr[_9_ELEM_ARR_SIZE]
        { 2, 3114.314, 314134.134, 134.13, 7647.76, 34534.653, 52362.13, 5.67, 1 };
    alignas(AVX_ALIGNMENT) static const float _16ElemArr[_16_ELEM_ARR_SIZE]
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    alignas(AVX_ALIGNMENT) static const float _17ElemArr[_17_ELEM_ARR_SIZE]
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    alignas(AVX_ALIGNMENT) static const float _24ElemArr[_24_ELEM_ARR_SIZE]
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
    alignas(AVX_ALIGNMENT) static const float _25ElemArr[_25_ELEM_ARR_SIZE]
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

    inline float *AllocBigArr()
    {
#if defined(_MSC_VER)
        float *bigArr = static_cast<float *>(_aligned_malloc(BIG_ARR_SIZE * sizeof(float), AVX_ALIGNMENT));
#else // _MSC_VER
        float *bigArr = static_cast<float *>(std::aligned_alloc(AVX_ALIGNMENT, BIG_ARR_SIZE * sizeof(float)));
#endif // _MSC_VER
        std::fill(bigArr, bigArr + BIG_ARR_SIZE, 1);

        return bigArr;
    }

    inline void FreeBigArr(float *bigArr)
    {
#if defined(_MSC_VER)
            _aligned_free(bigArr);
#else // _MSC_VER
            std::free(bigArr);
#endif // _MSC_VER
    }
} // namespace analysis

#endif // SUMS_SHARED_FIELDS_HPP