#ifndef SUMS_FIXTURE_HPP
#define SUMS_FIXUTRE_HPP

#include <simd/simd_common.hpp>

#include <gtest/gtest.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <functional>
#include <cstddef>
#include <numeric> // std::inclusive_scan

namespace tests
{
    class SumsTests : public testing::Test
    {
    private:
        bool _bigArrTest;

    protected:
        static const size_t _1_ELEM_ARR_SIZE = 1;
        static const size_t _8_ELEM_ARR_SIZE = 8;
        static const size_t _9_ELEM_ARR_SIZE = 9;
        static const size_t _16_ELEM_ARR_SIZE = 16;
        static const size_t _17_ELEM_ARR_SIZE = 17;
        static const size_t _24_ELEM_ARR_SIZE = 24;
        static const size_t _25_ELEM_ARR_SIZE = 25;
        const size_t BIG_ARR_SIZE = 15000000;

        alignas(AVX_ALIGNMENT) const float _1ElemArr[_1_ELEM_ARR_SIZE] { 2 };
        alignas(AVX_ALIGNMENT) const float _8ElemArr[_8_ELEM_ARR_SIZE] { 2, 1, 2.3, 1.3, 1.424, 13, 51341, 132413.1321 };
        alignas(AVX_ALIGNMENT) const float _9ElemArr[_9_ELEM_ARR_SIZE] { 2, 3114.314, 314134.134, 134.13, 7647.76, 34534.653, 52362.13, 5.67, 1 };
        alignas(AVX_ALIGNMENT) const float _16ElemArr[_16_ELEM_ARR_SIZE] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
        alignas(AVX_ALIGNMENT) const float _17ElemArr[_17_ELEM_ARR_SIZE] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
        alignas(AVX_ALIGNMENT) const float _24ElemArr[_24_ELEM_ARR_SIZE] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 };
        alignas(AVX_ALIGNMENT) const float _25ElemArr[_25_ELEM_ARR_SIZE] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

        float *bigArr;

        SumsTests()
        {
            std::string testName = testing::UnitTest::GetInstance()->current_test_info()->name();
            _bigArrTest = testName.find("Big") != std::string::npos;

            if (_bigArrTest)
            {
                bigArr = static_cast<float *>(std::aligned_alloc(AVX_ALIGNMENT, BIG_ARR_SIZE * sizeof(float)));
                std::fill(bigArr, bigArr + BIG_ARR_SIZE, 1);
            }
        }

        ~SumsTests()
        {
            if (_bigArrTest)
            {
                std::free(bigArr);
            }
        }

        void test_prefix_sum_stack(std::function<void(const float *, size_t, float *)> testedPrefixSum,
            const float *arr, size_t size)
        {
            alignas(32) float result[size];
            alignas(32) float expected[size];
            testedPrefixSum(arr, size, result);
            std::inclusive_scan(arr, arr + size, expected);

            for (size_t i = 0; i < size; i++)
            {
                EXPECT_FLOAT_EQ(result[i], expected[i]);
            }
        }
    };
} // namespace tests

#endif // SUMS_FIXTURE_HPP