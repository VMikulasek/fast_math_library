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
} // namespace tests
} // namespace analysis