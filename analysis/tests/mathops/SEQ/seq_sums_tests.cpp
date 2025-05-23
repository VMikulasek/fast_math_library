#include <mathops/sums_tests_fixture.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>

#include <gtest/gtest.h>
#include <numeric> // std::reduce

#if defined(_MSC_VER)
#include <malloc.h> // _aligned_malloc
#endif // _MSC_VER

namespace analysis
{
namespace tests
{
    class SeqSumsTests : public SumsTests
    {
    protected:
        void test_prefix_sum(const float *arr, size_t size)
        {
            SumsTests::test_prefix_sum(mathops::seq::prefix_sum<float>, arr, size);
        }
    };

    TEST_F(SeqSumsTests, Sum1ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_1ElemArr, _1_ELEM_ARR_SIZE),
                  std::reduce(_1ElemArr, _1ElemArr + _1_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, Sum8ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_8ElemArr, _8_ELEM_ARR_SIZE),
                  std::reduce(_8ElemArr, _8ElemArr + _8_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, Sum9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_9ElemArr, _9_ELEM_ARR_SIZE),
                  std::reduce(_9ElemArr, _9ElemArr + _9_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, Sum16ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_16ElemArr, _16_ELEM_ARR_SIZE),
                  std::reduce(_16ElemArr, _16ElemArr + _16_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, Sum17ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_17ElemArr, _17_ELEM_ARR_SIZE),
                  std::reduce(_17ElemArr, _17ElemArr + _17_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, Sum24ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_24ElemArr, _24_ELEM_ARR_SIZE),
                  std::reduce(_24ElemArr, _24ElemArr + _24_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, Sum25ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_25ElemArr, _25_ELEM_ARR_SIZE),
                  std::reduce(_25ElemArr, _25ElemArr + _25_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(SeqSumsTests, SumBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sum(_bigArr, BIG_ARR_SIZE),
                  std::reduce(_bigArr, _bigArr + BIG_ARR_SIZE, 0.0f));
    }

    TEST_F(SeqSumsTests, PrefixSum1ElemArr)
    {
        test_prefix_sum(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSum8ElemArr)
    {
        test_prefix_sum(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSum9ElemArr)
    {
        test_prefix_sum(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSum16ElemArr)
    {
        test_prefix_sum(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSum17ElemArr)
    {
        test_prefix_sum(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSum24ElemArr)
    {
        test_prefix_sum(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSum25ElemArr)
    {
        test_prefix_sum(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(SeqSumsTests, PrefixSumBigArr)
    {
        test_prefix_sum(_bigArr, BIG_ARR_SIZE);
    }
} // namespace tests
} // namespace analysis