#include <mathops/detail/VEC/vec_statisticals.hpp>
#include <mathops_shared_fields.hpp>
#include <mathops/mathops_tests_fixture.hpp>
#include <simd/simd_common.hpp>

#include <gtest/gtest.h>

#include <limits>

namespace analysis
{
namespace tests
{
    class AvxStatisticalsTests : public MathopsTests {};

    TEST_F(AvxStatisticalsTests, MinArrWithZero)
    {
        auto res = mathops::vec::min<float, simd::InstructionSet::AVX>(analysis::_arrContainingZero, analysis::_9_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, MinArrWithInf)
    {
        auto res = mathops::vec::min<float, simd::InstructionSet::AVX>(analysis::_arrContainingInf, analysis::_25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 1.f);
    }
    TEST_F(AvxStatisticalsTests, MinArrWithMinusInf)
    {
        auto res = mathops::vec::min<float, simd::InstructionSet::AVX>(analysis::_arrContainingMinusInf, analysis::_25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, -std::numeric_limits<float>::infinity());
    }
    TEST_F(AvxStatisticalsTests, MinBigArr)
    {
        std::fill(_bigArr, _bigArr + BIG_ARR_SIZE, 3.4f);

        auto res = mathops::vec::min<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 3.4f);
    }
    TEST_F(AvxStatisticalsTests, MaxArrWithZero)
    {
        auto res = mathops::vec::max<float, simd::InstructionSet::AVX>(analysis::_arrContainingZero, analysis::_9_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 314134.134f);
    }
    TEST_F(AvxStatisticalsTests, MaxArrWithInf)
    {
        auto res = mathops::vec::max<float, simd::InstructionSet::AVX>(analysis::_arrContainingInf, analysis::_25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::numeric_limits<float>::infinity());
    }
    TEST_F(AvxStatisticalsTests, MaxArrWithMinusInf)
    {
        auto res = mathops::vec::max<float, simd::InstructionSet::AVX>(analysis::_arrContainingMinusInf, analysis::_25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 24.f);
    }
    TEST_F(AvxStatisticalsTests, MaxBigArr)
    {
        std::fill(_bigArr, _bigArr + BIG_ARR_SIZE, 3.4f);

        auto res = mathops::vec::max<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 3.4f);
    }

    TEST_F(AvxStatisticalsTests, ArithmeticMeanZeroLength)
    {
        auto res = mathops::vec::arithmetic_mean<float, simd::InstructionSet::AVX>(analysis::_16ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, ArithmeticMeanArrWithNegativeAndPositiveNumbers)
    {
        auto res = mathops::vec::arithmetic_mean<float, simd::InstructionSet::AVX>(analysis::_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, -0.965f);
    }
    TEST_F(AvxStatisticalsTests, ArithmeticMeanBigArr)
    {
        _bigArr[0] = 0.f;
        _bigArr[BIG_ARR_SIZE - 1] = 2.f;
        auto res = mathops::vec::arithmetic_mean<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 1.f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMeanZeroLength)
    {
        auto res = mathops::vec::geometric_mean<float, simd::InstructionSet::AVX>(analysis::_16ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMeanArrContainingZero)
    {
        auto res = mathops::vec::geometric_mean<float, simd::InstructionSet::AVX>(analysis::_arrContainingZero, _9_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMean16ElemArr)
    {
        auto res = mathops::vec::geometric_mean<float, simd::InstructionSet::AVX>(analysis::_16ElemArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 6.800466798268f);
    }
    TEST_F(AvxStatisticalsTests, GeometricMeanBigArr)
    {
        auto res = mathops::vec::geometric_mean<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 1.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanZeroLength)
    {
        auto res = mathops::vec::weighted_mean<float, simd::InstructionSet::AVX>(analysis::_16ElemArr, _16ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanZeroWeights)
    {
        auto res = mathops::vec::weighted_mean<float, simd::InstructionSet::AVX>(analysis::_16ElemArr, analysis::_16ElemZeroArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMean9ElemArr)
    {
        auto res = mathops::vec::weighted_mean<float, simd::InstructionSet::AVX>(analysis::_9ElemArr, analysis::_9ElemArr, _9_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 249269.1737791f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanBigArr)
    {
        float *bigArr2 = AllocBigArr();
        _bigArr[0] = 0;
        _bigArr[BIG_ARR_SIZE - 1] = 2;
        bigArr2[1] = 0;
        bigArr2[BIG_ARR_SIZE - 2] = 2;
        auto res = mathops::vec::weighted_mean<float, simd::InstructionSet::AVX>(_bigArr, bigArr2, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 1.f);
    }
    TEST_F(AvxStatisticalsTests, WeightedMeanBigArr1)
    {
        alignas(32) float arr[8] {1, 1, 1, 1, 1, 1, 1, 1};
        auto res = mathops::vec::weighted_mean<float, simd::InstructionSet::AVX>(arr, arr, 8);
        EXPECT_FLOAT_EQ(res, 1.f);
    }

    TEST_F(AvxStatisticalsTests, VarianceZeroLengthArr)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_9ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceArrWithAllSameValues)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_16ElemZeroArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceArrWithPositiveAndNegativeValues)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 4.0396458f);
    }
    TEST_F(AvxStatisticalsTests, VarianceBigArr)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }

    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesZeroLengthArr)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_9ElemArr, _9ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesArrWithAllSameValues)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_16ElemZeroArr, _16ElemArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesArrWithPositiveAndNegativeValues)
    {
        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_25ElemArrMinusPiPi, _25ProbabilitiesArr, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 3.41044051f);
    }
    TEST_F(AvxStatisticalsTests, VarianceWithProbabilitiesBigArrZeroProbabilities)
    {
        float *bigArr2 = AllocBigArr();
        std::fill(bigArr2, bigArr2 + BIG_ARR_SIZE, 0.f);

        auto res = mathops::vec::variance<float, simd::InstructionSet::AVX>(_bigArr, bigArr2, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }

    TEST_F(AvxStatisticalsTests, SampleVarianceZeroLengthArr)
    {
        auto res = mathops::vec::sample_variance<float, simd::InstructionSet::AVX>(_9ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleVarianceArrWithAllSameValues)
    {
        auto res = mathops::vec::sample_variance<float, simd::InstructionSet::AVX>(_16ElemZeroArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleVarianceArrWithPositiveAndNegativeValues)
    {
        auto res = mathops::vec::sample_variance<float, simd::InstructionSet::AVX>(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 4.2079643f);
    }
    TEST_F(AvxStatisticalsTests, SampleVarianceBigArr)
    {
        auto res = mathops::vec::sample_variance<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }

    TEST_F(AvxStatisticalsTests, StdDeviationZeroLengthArr)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_9ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationArrWithAllSameValues)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_16ElemZeroArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationArrWithPositiveAndNegativeValues)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 2.009887f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationBigArr)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }

    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesZeroLengthArr)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_9ElemArr, _9ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesArrWithAllSameValues)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_16ElemZeroArr, _16ElemArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesArrWithPositiveAndNegativeValues)
    {
        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_25ElemArrMinusPiPi, _25ProbabilitiesArr, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 1.846737802179833f);
    }
    TEST_F(AvxStatisticalsTests, StdDeviationWithProbabilitiesBigArrZeroProbabilities)
    {
        float *bigArr2 = AllocBigArr();
        std::fill(bigArr2, bigArr2 + BIG_ARR_SIZE, 0.f);

        auto res = mathops::vec::std_deviation<float, simd::InstructionSet::AVX>(_bigArr, bigArr2, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }

    TEST_F(AvxStatisticalsTests, SampleStdDeviationZeroLengthArr)
    {
        auto res = mathops::vec::sample_std_deviation<float, simd::InstructionSet::AVX>(_9ElemArr, 0);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleStdDeviationArrWithAllSameValues)
    {
        auto res = mathops::vec::sample_std_deviation<float, simd::InstructionSet::AVX>(_16ElemZeroArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
    TEST_F(AvxStatisticalsTests, SampleStdDeviationArrWithPositiveAndNegativeValues)
    {
        auto res = mathops::vec::sample_std_deviation<float, simd::InstructionSet::AVX>(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 2.0513323f);
    }
    TEST_F(AvxStatisticalsTests, SampleStdDeviationBigArr)
    {
        auto res = mathops::vec::sample_std_deviation<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, 0.f);
    }
} // namespace tests
} // namespace analysis