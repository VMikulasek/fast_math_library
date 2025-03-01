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

    TEST_F(SeqStatisticalsTests, ArithmeticMeanZeroLength)
    {
        EXPECT_FLOAT_EQ(mathops::seq::arithmetic_mean(analysis::_16ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, ArithmeticMeanArrWithNegativeAndPositiveNumbers)
    {
        EXPECT_FLOAT_EQ(mathops::seq::arithmetic_mean(analysis::_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE), -0.965f);
    }
    TEST_F(SeqStatisticalsTests, ArithmeticMeanBigArr)
    {
        _bigArr[0] = 0.f;
        _bigArr[BIG_ARR_SIZE - 1] = 2.f;
        EXPECT_FLOAT_EQ(mathops::seq::arithmetic_mean(_bigArr, BIG_ARR_SIZE), 1.f);
    }
    TEST_F(SeqStatisticalsTests, GeometricMeanZeroLength)
    {
        EXPECT_FLOAT_EQ(mathops::seq::geometric_mean(analysis::_16ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, GeometricMeanArrContainingZero)
    {
        EXPECT_FLOAT_EQ(mathops::seq::geometric_mean(analysis::_arrContainingZero, _9_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, GeometricMean16ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::geometric_mean(analysis::_16ElemArr, _16_ELEM_ARR_SIZE), 6.800466798268f);
    }
    TEST_F(SeqStatisticalsTests, GeometricMeanBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::geometric_mean(_bigArr, BIG_ARR_SIZE), 1.f);
    }

    TEST_F(SeqStatisticalsTests, WeightedMeanZeroLength)
    {
        EXPECT_FLOAT_EQ(mathops::seq::weighted_mean(analysis::_16ElemArr, _16ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, WeightedMeanZeroWeights)
    {
        EXPECT_FLOAT_EQ(mathops::seq::weighted_mean(analysis::_16ElemArr, analysis::_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, WeightedMean9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::weighted_mean(analysis::_9ElemArr, analysis::_9ElemArr, _9_ELEM_ARR_SIZE), 249269.1737791f);
    }
    TEST_F(SeqStatisticalsTests, WeightedMeanBigArr)
    {
        float *bigArr2 = AllocBigArr();
        _bigArr[0] = 0;
        _bigArr[BIG_ARR_SIZE - 1] = 2;
        bigArr2[1] = 0;
        bigArr2[BIG_ARR_SIZE - 2] = 2;
        EXPECT_FLOAT_EQ(mathops::seq::weighted_mean(_bigArr, bigArr2, BIG_ARR_SIZE), 1.f);
    }

} // namespace tests
} // namespace analysis