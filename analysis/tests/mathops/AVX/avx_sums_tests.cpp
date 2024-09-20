#ifdef HAS_AVX

#include <mathops/sums_tests_fixture.hpp>
#include <mathops/detail/AVX/avx_sums.hpp>

#include <gtest/gtest.h>
#include <numeric> // std::reduce
#include <cstdlib>

#if defined(_MSC_VER)
#include <malloc.h> // _aligned_malloc
#endif // _MSC_VER

namespace analysis
{
namespace tests
{
    class AvxSumsTests : public SumsTests
    {
    protected:
        void test_prefix_sum(const float *arr, size_t size)
        {
            SumsTests::test_prefix_sum(mathops::avx::prefix_sum, arr, size);
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
        EXPECT_FLOAT_EQ(mathops::avx::sum(_bigArr, BIG_ARR_SIZE),
                  std::reduce(_bigArr, _bigArr + BIG_ARR_SIZE, 0.0f));
    }

    TEST_F(AvxSumsTests, PrefixSum1ElemArr)
    {
        test_prefix_sum(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum8ElemArr)
    {
        test_prefix_sum(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum9ElemArr)
    {
        test_prefix_sum(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum16ElemArr)
    {
        test_prefix_sum(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum17ElemArr)
    {
        test_prefix_sum(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum24ElemArr)
    {
        test_prefix_sum(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum25ElemArr)
    {
        test_prefix_sum(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSumBigArr)
    {
        test_prefix_sum(_bigArr, BIG_ARR_SIZE);
    }
} // namespace tests
} // namespace analysis

#endif // HAS_AVX