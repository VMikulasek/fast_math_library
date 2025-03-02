#include <mathops/detail/AVX/avx_statisticals.hpp>
#include <mathops_shared_fields.hpp>
#include <mathops/mathops_tests_fixture.hpp>

#include <gtest/gtest.h>

#include <limits>

namespace analysis
{
namespace tests
{
    class AvxStatisticalsTests : public MathopsTests {};

    TEST_F(AvxStatisticalsTests, MinArrWithZero)
    {
        EXPECT_FLOAT_EQ(mathops::avx::min(analysis::_arrContainingZero, analysis::_9_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, MinArrWithInf)
    {
        EXPECT_FLOAT_EQ(mathops::avx::min(analysis::_arrContainingInf, analysis::_25_ELEM_ARR_SIZE), 1.f);
    }
    TEST_F(AvxStatisticalsTests, MinArrWithMinusInf)
    {
        EXPECT_FLOAT_EQ(mathops::avx::min(analysis::_arrContainingMinusInf, analysis::_25_ELEM_ARR_SIZE), -std::numeric_limits<float>::infinity());
    }
    TEST_F(AvxStatisticalsTests, MinBigArr)
    {
        std::fill(_bigArr, _bigArr + BIG_ARR_SIZE, 3.4f);

        EXPECT_FLOAT_EQ(mathops::avx::min(_bigArr, BIG_ARR_SIZE), 3.4f);
    }
    TEST_F(AvxStatisticalsTests, MaxArrWithZero)
    {
        EXPECT_FLOAT_EQ(mathops::avx::max(analysis::_arrContainingZero, analysis::_9_ELEM_ARR_SIZE), 314134.134f);
    }
    TEST_F(AvxStatisticalsTests, MaxArrWithInf)
    {
        EXPECT_FLOAT_EQ(mathops::avx::max(analysis::_arrContainingInf, analysis::_25_ELEM_ARR_SIZE), std::numeric_limits<float>::infinity());
    }
    TEST_F(AvxStatisticalsTests, MaxArrWithMinusInf)
    {
        EXPECT_FLOAT_EQ(mathops::avx::max(analysis::_arrContainingMinusInf, analysis::_25_ELEM_ARR_SIZE), 24.f);
    }
    TEST_F(AvxStatisticalsTests, MaxBigArr)
    {
        std::fill(_bigArr, _bigArr + BIG_ARR_SIZE, 3.4f);

        EXPECT_FLOAT_EQ(mathops::avx::max(_bigArr, BIG_ARR_SIZE), 3.4f);
    }

    TEST_F(AvxStatisticalsTests, ArithmeticMeanZeroLength)
    {
        EXPECT_FLOAT_EQ(mathops::avx::arithmetic_mean(analysis::_16ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, ArithmeticMeanArrWithNegativeAndPositiveNumbers)
    {
        EXPECT_FLOAT_EQ(mathops::avx::arithmetic_mean(analysis::_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE), -0.965f);
    }
    TEST_F(AvxStatisticalsTests, ArithmeticMeanBigArr)
    {
        _bigArr[0] = 0.f;
        _bigArr[BIG_ARR_SIZE - 1] = 2.f;
        EXPECT_FLOAT_EQ(mathops::avx::arithmetic_mean(_bigArr, BIG_ARR_SIZE), 1.f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMeanZeroLength)
    {
        EXPECT_FLOAT_EQ(mathops::avx::geometric_mean(analysis::_16ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMeanArrContainingZero)
    {
        EXPECT_FLOAT_EQ(mathops::avx::geometric_mean(analysis::_arrContainingZero, _9_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMean16ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::geometric_mean(analysis::_16ElemArr, _16_ELEM_ARR_SIZE), 6.800466798268f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMeanBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::geometric_mean(_bigArr, BIG_ARR_SIZE), 1.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanZeroLength)
    {
        EXPECT_FLOAT_EQ(mathops::avx::weighted_mean(analysis::_16ElemArr, _16ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanZeroWeights)
    {
        EXPECT_FLOAT_EQ(mathops::avx::weighted_mean(analysis::_16ElemArr, analysis::_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMean9ElemArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::weighted_mean(analysis::_9ElemArr, analysis::_9ElemArr, _9_ELEM_ARR_SIZE), 249269.1737791f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanBigArr)
    {
        float *bigArr2 = AllocBigArr();
        _bigArr[0] = 0;
        _bigArr[BIG_ARR_SIZE - 1] = 2;
        bigArr2[1] = 0;
        bigArr2[BIG_ARR_SIZE - 2] = 2;
        EXPECT_FLOAT_EQ(mathops::avx::weighted_mean(_bigArr, bigArr2, BIG_ARR_SIZE), 1.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanBigArr1)
    {
        alignas(32) float arr[8] {1, 1, 1, 1, 1, 1, 1, 1};
        EXPECT_FLOAT_EQ(mathops::avx::weighted_mean(arr, arr, 8), 1.f);
    }

    TEST_F(AvxStatisticalsTests, VarianceZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_9ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 4.0396458f);
    }
    TEST_F(AvxStatisticalsTests, VarianceBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_bigArr, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_9ElemArr, _9ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_16ElemZeroArr, _16ElemArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::variance(_25ElemArrMinusPiPi, _25ProbabilitiesArr, _25_ELEM_ARR_SIZE), 3.41044051f);
    }
    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesBigArrZeroProbabilities)
    {
        float *bigArr2 = AllocBigArr();
        std::fill(bigArr2, bigArr2 + BIG_ARR_SIZE, 0.f);
        EXPECT_FLOAT_EQ(mathops::avx::variance(_bigArr, bigArr2, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(AvxStatisticalsTests, SampleVarianceZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_variance(_9ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleVarianceArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_variance(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleVarianceArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_variance(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 4.2079643f);
    }
    TEST_F(AvxStatisticalsTests, SampleVarianceBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_variance(_bigArr, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(AvxStatisticalsTests, StdDeviationZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_9ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 2.009887f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_bigArr, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_9ElemArr, _9ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_16ElemZeroArr, _16ElemArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_25ElemArrMinusPiPi, _25ProbabilitiesArr, _25_ELEM_ARR_SIZE), 1.846737802179833f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesBigArrZeroProbabilities)
    {
        float *bigArr2 = AllocBigArr();
        std::fill(bigArr2, bigArr2 + BIG_ARR_SIZE, 0.f);
        EXPECT_FLOAT_EQ(mathops::avx::std_deviation(_bigArr, bigArr2, BIG_ARR_SIZE), 0.f);
    }

    TEST_F(AvxStatisticalsTests, SampleStdDeviationZeroLengthArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_std_deviation(_9ElemArr, 0), 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleStdDeviationArrWithAllSameValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_std_deviation(_16ElemZeroArr, _16_ELEM_ARR_SIZE), 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleStdDeviationArrWithPositiveAndNegativeValues)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_std_deviation(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE), 2.0513323f);
    }
    TEST_F(AvxStatisticalsTests, SampleStdDeviationBigArr)
    {
        EXPECT_FLOAT_EQ(mathops::avx::sample_std_deviation(_bigArr, BIG_ARR_SIZE), 0.f);
    }
} // namespace tests
} // namespace analysis