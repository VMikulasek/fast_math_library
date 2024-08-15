#include <mathops/sums_fixture.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>

#include <gtest/gtest.h>
#include <numeric> // std::reduce

namespace tests
{
    class SeqSumsTests : public SumsTests
    {};

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
        EXPECT_FLOAT_EQ(mathops::seq::sum(bigArr, BIG_ARR_SIZE),
                  std::reduce(bigArr, bigArr + BIG_ARR_SIZE, 0.0f));
    }
} // namespace testing