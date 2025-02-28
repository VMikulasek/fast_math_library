#include <mathops/detail/SEQ/seq_statisticals.hpp>
#include <mathops_shared_fields.hpp>
#include <mathops/mathops_tests_fixture.hpp>

#include <gtest/gtest.h>

#include <limits>

namespace analysis
{
namespace tests
{
    class SeqStatisticalsTests : public MathopsTests {};

    TEST_F(SeqStatisticalsTests, MinArrWithZero)
    {
        EXPECT_FLOAT_EQ(mathops::seq::min(analysis::_arrContainingZero, analysis::_9_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, MinArrWithInf)
    {
        EXPECT_FLOAT_EQ(mathops::seq::min(analysis::_arrContainingInf, analysis::_25_ELEM_ARR_SIZE), 1.f);
    }
    TEST_F(SeqStatisticalsTests, MinArrWithMinusInf)
    {
        EXPECT_FLOAT_EQ(mathops::seq::min(analysis::_arrContainingMinusInf, analysis::_25_ELEM_ARR_SIZE), -std::numeric_limits<float>::infinity());
    }
    TEST_F(SeqStatisticalsTests, MinBigArr)
    {
        std::fill(_bigArr, _bigArr + BIG_ARR_SIZE, 3.4f);

        EXPECT_FLOAT_EQ(mathops::seq::min(_bigArr, BIG_ARR_SIZE), 3.4f);
    }
    TEST_F(SeqStatisticalsTests, MaxArrWithZero)
    {
        EXPECT_FLOAT_EQ(mathops::seq::max(analysis::_arrContainingZero, analysis::_9_ELEM_ARR_SIZE), 314134.134f);
    }
    TEST_F(SeqStatisticalsTests, MaxArrWithInf)
    {
        EXPECT_FLOAT_EQ(mathops::seq::max(analysis::_arrContainingInf, analysis::_25_ELEM_ARR_SIZE), std::numeric_limits<float>::infinity());
    }
    TEST_F(SeqStatisticalsTests, MaxArrWithMinusInf)
    {
        EXPECT_FLOAT_EQ(mathops::seq::max(analysis::_arrContainingMinusInf, analysis::_25_ELEM_ARR_SIZE), 24.f);
    }
    TEST_F(SeqStatisticalsTests, MaxBigArr)
    {
        std::fill(_bigArr, _bigArr + BIG_ARR_SIZE, 3.4f);

        EXPECT_FLOAT_EQ(mathops::seq::max(_bigArr, BIG_ARR_SIZE), 3.4f);
    }
} // namespace tests
} // namespace analysis