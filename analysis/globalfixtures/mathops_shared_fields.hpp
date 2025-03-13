#ifndef MATHOPS_SHARED_FIELDS_HPP
#define MATHOPS_SHARED_FIELDS_HPP

#include <simd/simd_common.hpp>
#include <common/detail/memory_common.inl>

#include <cstddef>
#include <cstdlib>      // std::aligned_alloc
#include <algorithm>    // std::fill
#include <cmath>        // INFINITY

namespace analysis
{
    static const size_t _1_ELEM_ARR_SIZE = 1;
    static const size_t _8_ELEM_ARR_SIZE = 8;
    static const size_t _9_ELEM_ARR_SIZE = 9;
    static const size_t _16_ELEM_ARR_SIZE = 16;
    static const size_t _17_ELEM_ARR_SIZE = 17;
    static const size_t _24_ELEM_ARR_SIZE = 24;
    static const size_t _25_ELEM_ARR_SIZE = 25;
    static const size_t MEDIUM_ARR_SIZE = 10000;
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

    alignas(AVX_ALIGNMENT) static const float _8ElemArrMinusPiPi[_8_ELEM_ARR_SIZE]
        { 2, 1, 2.3, 1.3, 1.424, 3.14, -3.14, 2.1341 };
    alignas(AVX_ALIGNMENT) static const float _9ElemArrMinusPiPi[_9_ELEM_ARR_SIZE]
        { 2, 2.314, 1.134, 134.13, 1.76, 0.653, -0.13, -1.67, 1 };
    alignas(AVX_ALIGNMENT) static const float _16ElemArrMinusPiPi[_16_ELEM_ARR_SIZE]
        { -3.14, -2.84, -2.54, -2.24, -2.04, -1.74, -1.44, -1.14, -0.84, -0.54, -0.24, 0.06, 0.36, 0.66, 0.96, 1.26 };
    alignas(AVX_ALIGNMENT) static const float _17ElemArrMinusPiPi[_17_ELEM_ARR_SIZE]
        { -3.14, -2.84, -2.54, -2.24, -2.04, -1.74, -1.44, -1.14, -0.84, -0.54, -0.24, 0.06, 0.36, 0.66, 0.96, 1.26, 1.56 };
    alignas(AVX_ALIGNMENT) static const float _24ElemArrMinusPiPi[_24_ELEM_ARR_SIZE]
        { -3.14, -2.84, -2.54, -2.24, -2.04, -1.74, -1.44, -1.14, -0.84, -0.54, -0.24, 0.06, 0.36, 0.66, 0.96, 1.26, 1.56, 1.86, 2.06, 2.36, 2.66, 2.96, 2.99, 3.02 };
    alignas(AVX_ALIGNMENT) static const float _25ElemArrMinusPiPi[_25_ELEM_ARR_SIZE]
        { -3.14, -2.84, -2.54, -2.24, -2.04, -1.74, -1.44, -1.14, -0.84, -0.54, -0.24, 0.06, 0.36, 0.66, 0.96, 1.26, 1.56, 1.86, 2.06, 2.36, 2.66, 2.96, 2.99, 3.02, 3.05 };

    alignas(AVX_ALIGNMENT) static const float _arrContainingZero[_9_ELEM_ARR_SIZE]
        { 0, 3114.314, 314134.134, 134.13, 7647.76, 34534.653, 52362.13, 5.67, 1 };
    alignas(AVX_ALIGNMENT) static const float _arrContainingInf[_25_ELEM_ARR_SIZE]
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, INFINITY };
    alignas(AVX_ALIGNMENT) static const float _arrContainingMinusInf[_25_ELEM_ARR_SIZE]
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, -INFINITY };
    alignas(AVX_ALIGNMENT) static const float _16ElemZeroArr[_16_ELEM_ARR_SIZE]
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    alignas(AVX_ALIGNMENT) static const float _25ProbabilitiesArr[_25_ELEM_ARR_SIZE]
        { 0.01, 0.05, 0.05, 0.03, 0.02, 0.06, 0.05, 0.04, 0.01, 0.08,
        0.03, 0.02, 0.10, 0.05, 0.06, 0.02, 0.07, 0.01, 0.06, 0.03,  
        0.04, 0.02, 0.02, 0.02, 0.05 };

    alignas(AVX_ALIGNMENT) static const int _16ElemPositiveAndNegativeValues[_16_ELEM_ARR_SIZE]
        { -25, -10, 134, 33, -66, 0, 1, 1, -74, 5, -9, -8, -7, -6, 11, 22 };
    alignas(AVX_ALIGNMENT) static const int _9ElemIntArr[_9_ELEM_ARR_SIZE]
        { 2, 3114, 314134, 314134, 7647, 34534, 52362, 5, 1 };
    

    inline float *AllocBigArr()
    {
        float *bigArr = _alloc_aligned_memory_float(BIG_ARR_SIZE * sizeof(float), AVX_ALIGNMENT);

        std::fill(bigArr, bigArr + BIG_ARR_SIZE, 1.f);

        return bigArr;
    }

    inline int *AllocBigIntArr()
    {
        int *bigArr = reinterpret_cast<int *>(_alloc_aligned_memory(BIG_ARR_SIZE * sizeof(int), AVX_ALIGNMENT));
        
        std::fill(bigArr, bigArr + BIG_ARR_SIZE, 1.f);
    
        return bigArr;
    }

    inline float *AllocMediumArr()
    {
        float *mediumArr = _alloc_aligned_memory_float(MEDIUM_ARR_SIZE * sizeof(float), AVX_ALIGNMENT);

        std::fill(mediumArr, mediumArr + MEDIUM_ARR_SIZE, 1.f);

        return mediumArr;
    }
} // namespace analysis

#endif // MATHOPS_SHARED_FIELDS_HPP