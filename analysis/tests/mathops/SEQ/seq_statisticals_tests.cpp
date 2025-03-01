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

    TEST_F(SeqStatisticalsTests, ModeArrWithNegativeAndPositiveValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::mode(_16ElemPositiveAndNegativeValues, _16_ELEM_ARR_SIZE), 1);
    }
    TEST_F(SeqStatisticalsTests, Mode9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::mode(_9ElemIntArr, _9_ELEM_ARR_SIZE), 314134);
    }
    TEST_F(SeqStatisticalsTests, ModeBigArr)
    {
        int *bigArr = AllocBigIntArr();
        bigArr[0] = 0;
        bigArr[BIG_ARR_SIZE - 1] = 2;
        EXPECT_FLOAT_EQ(mathops::seq::mode(bigArr, BIG_ARR_SIZE), 1);
    }
    TEST_F(SeqStatisticalsTests, MedianArrWithNegativeAndPositiveValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::median(_16ElemPositiveAndNegativeValues, _16_ELEM_ARR_SIZE), -3.f);
    }
    TEST_F(SeqStatisticalsTests, Median9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::median(_9ElemIntArr, _9_ELEM_ARR_SIZE), 7647.f);
    }
    TEST_F(SeqStatisticalsTests, MedianBigArr)
    {
        int *bigArr = AllocBigIntArr();
        bigArr[0] = 0;
        bigArr[BIG_ARR_SIZE - 1] = 2;
        EXPECT_FLOAT_EQ(mathops::seq::median(bigArr, BIG_ARR_SIZE), 1.f);
    }
    TEST_F(SeqStatisticalsTests, MedianFloatArrWithNegativeAndPositiveValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::median(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE), -0.99f);
    }
    TEST_F(SeqStatisticalsTests, MedianFloat9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::median(_9ElemArr, _9_ELEM_ARR_SIZE), 3114.314f);
    }
    TEST_F(SeqStatisticalsTests, MedianFloatBigArr)
    {
        _bigArr[0] = 0;
        _bigArr[BIG_ARR_SIZE - 1] = 2;
        EXPECT_FLOAT_EQ(mathops::seq::median(_bigArr, BIG_ARR_SIZE), 1.f);
    }

    TEST_F(SeqStatisticalsTests, VarianceZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_9ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, VarianceArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, VarianceArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 4.0396458f);
    }
    TEST_F(SeqStatisticalsTests, VarianceBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_bigArr, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(SeqStatisticalsTests, VarianceWithProbabilitiesZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_9ElemArr, _9ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, VarianceWithProbabilitiesArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_16ElemZeroArr, _16ElemArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, VarianceWithProbabilitiesArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::variance(_25ElemArrMinusPiPi, _25ProbabilitiesArr, _25_ELEM_ARR_SIZE), 3.41044051f);
    }
    TEST_F(SeqStatisticalsTests, VarianceWithProbabilitiesBigArrZeroProbabilities)
    {
        float *bigArr2 = AllocBigArr();
        std::fill(bigArr2, bigArr2 + BIG_ARR_SIZE, 0.f);
        EXPECT_FLOAT_EQ(mathops::seq::variance(_bigArr, bigArr2, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(SeqStatisticalsTests, SampleVarianceZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_variance(_9ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, SampleVarianceArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_variance(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, SampleVarianceArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_variance(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 4.2079643f);
    }
    TEST_F(SeqStatisticalsTests, SampleVarianceBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_variance(_bigArr, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(SeqStatisticalsTests, StdDeviationZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_9ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, StdDeviationArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, StdDeviationArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 2.009887f);
    }
    TEST_F(SeqStatisticalsTests, StdDeviationBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_bigArr, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(SeqStatisticalsTests, StdDeviationWithProbabilitiesZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_9ElemArr, _9ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, StdDeviationWithProbabilitiesArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_16ElemZeroArr, _16ElemArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, StdDeviationWithProbabilitiesArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_25ElemArrMinusPiPi, _25ProbabilitiesArr, _25_ELEM_ARR_SIZE), 1.846737802179833f);
    }
    TEST_F(SeqStatisticalsTests, StdDeviationWithProbabilitiesBigArrZeroProbabilities)
    {
        float *bigArr2 = AllocBigArr();
        std::fill(bigArr2, bigArr2 + BIG_ARR_SIZE, 0.f);
        EXPECT_FLOAT_EQ(mathops::seq::std_deviation(_bigArr, bigArr2, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(SeqStatisticalsTests, SampleStdDeviationZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_std_deviation(_9ElemArr, 0), 0.f);
    }
    TEST_F(SeqStatisticalsTests, SampleStdDeviationArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_std_deviation(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(SeqStatisticalsTests, SampleStdDeviationArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_std_deviation(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 2.0513323f);
    }
    TEST_F(SeqStatisticalsTests, SampleStdDeviationBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::seq::sample_std_deviation(_bigArr, BIG_ARR_SIZE), 0.f);
    }
} // namespace tests
} // namespace analysis