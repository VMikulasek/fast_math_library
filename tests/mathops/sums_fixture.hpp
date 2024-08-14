#ifndef SUMS_FIXTURE_HPP
#define SUMS_FIXUTRE_HPP

#include <simd/simd_common.hpp>

#include <gtest/gtest.h>
#include <cstdlib>
#include <algorithm>

namespace tests
{
    class SumsTests : public testing::Test
    {
    protected:
        alignas(AVX_ALIGNMENT) const float _1ElemArr[1] { 2 };
        alignas(AVX_ALIGNMENT) const float _8ElemArr[8] { 2, 1, 2.3, 1.3, 1.424, 13, 51341, 132413.1321 };
        alignas(AVX_ALIGNMENT) const float _9ElemArr[9] { 2, 3114.314, 314134.134, 134.13, 7647.76, 34534.653, 52362.13, 5.67, 1 };
        alignas(AVX_ALIGNMENT) const float _16ElemArr[16] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
        alignas(AVX_ALIGNMENT) const float _17ElemArr[17] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
        alignas(AVX_ALIGNMENT) const float _24ElemArr[24] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
        alignas(AVX_ALIGNMENT) const float _25ElemArr[25] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

        float *bigArr;

        const size_t BIG_ARR_SIZE = 1000000000;

        SumsTests()
        {
            bigArr = static_cast<float *>(std::aligned_alloc(AVX_ALIGNMENT, BIG_ARR_SIZE * sizeof(float)));
            std::fill(bigArr, bigArr + BIG_ARR_SIZE, 1);
        }

        ~SumsTests()
        {
            std::free(bigArr);
        }
    };
} // namespace tests

#endif // SUMS_FIXTURE_HPP