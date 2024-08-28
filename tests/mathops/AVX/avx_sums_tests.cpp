#if HAS_AVX

#include <mathops/sums_fixture.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>

#include <gtest/gtest.h>
#include <numeric> // std::reduce

namespace tests
{
    class AvxSumsTests : public SumsTests
    {
    protected:
        void test_prefix_sum_stack(const float *arr, size_t size)
        {
            SumsTests::test_prefix_sum_stack(mathops::avx::prefix_sum, arr, size);
        }
    };

    TEST_F(AvxSumsTests, Sum1ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_1ElemArr, _1_ELEM_ARR_SIZE),
                  std::reduce(_1ElemArr, _1ElemArr + _1_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum8ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_8ElemArr, _8_ELEM_ARR_SIZE),
                  std::reduce(_8ElemArr, _8ElemArr + _8_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_9ElemArr, _9_ELEM_ARR_SIZE),
                  std::reduce(_9ElemArr, _9ElemArr + _9_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum16ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_16ElemArr, _16_ELEM_ARR_SIZE),
                  std::reduce(_16ElemArr, _16ElemArr + _16_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum17ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_17ElemArr, _17_ELEM_ARR_SIZE),
                  std::reduce(_17ElemArr, _17ElemArr + _17_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum24ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_24ElemArr, _24_ELEM_ARR_SIZE),
                  std::reduce(_24ElemArr, _24ElemArr + _24_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum25ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(_25ElemArr, _25_ELEM_ARR_SIZE),
                  std::reduce(_25ElemArr, _25ElemArr + _25_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, SumBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sum(bigArr, BIG_ARR_SIZE),
                  std::reduce(bigArr, bigArr + BIG_ARR_SIZE, 0.0f));
    }

    TEST_F(AvxSumsTests, PrefixSum1ElemArr)
    {
        test_prefix_sum_stack(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum8ElemArr)
    {
        test_prefix_sum_stack(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum9ElemArr)
    {
        test_prefix_sum_stack(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum16ElemArr)
    {
        test_prefix_sum_stack(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum17ElemArr)
    {
        test_prefix_sum_stack(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum24ElemArr)
    {
        test_prefix_sum_stack(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum25ElemArr)
    {
        test_prefix_sum_stack(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSumBigArr)
    {
        float *resultArr = static_cast<float *>(std::aligned_alloc(AVX_ALIGNMENT, BIG_ARR_SIZE * sizeof(float)));
        float *expectedArr = static_cast<float *>(std::aligned_alloc(AVX_ALIGNMENT, BIG_ARR_SIZE * sizeof(float)));

        mathops::avx::prefix_sum(bigArr, BIG_ARR_SIZE, resultArr);
        std::inclusive_scan(bigArr, bigArr + BIG_ARR_SIZE, expectedArr);

        for (size_t i = 0; i < BIG_ARR_SIZE; i++)
        {
            EXPECT_EQ(resultArr[i], expectedArr[i]);
        }

        free(resultArr);
        free(expectedArr);
    }
} // namespace testing

#endif // HAS_AVX