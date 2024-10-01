#include <mathops/transcedentals_tests_fixture.hpp>
#include <mathops/transcedentals.hpp>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    TEST_F(TranscedentalsTests, SqrtZero)
    {
        EXPECT_FLOAT_EQ(mathops::sqrt(0), std::sqrt(0));
    }
    TEST_F(TranscedentalsTests, SqrtPerfect)
    {
        EXPECT_FLOAT_EQ(mathops::sqrt(9), std::sqrt(9));
    }
    TEST_F(TranscedentalsTests, SqrtReal)
    {
        EXPECT_FLOAT_EQ(mathops::sqrt(realNumber), std::sqrt(realNumber));
    }
    TEST_F(TranscedentalsTests, SqrtSmall)
    {
        EXPECT_FLOAT_EQ(mathops::sqrt(smallNumber), std::sqrt(smallNumber));
    }
    TEST_F(TranscedentalsTests, SqrtNegative)
    {
        EXPECT_TRUE(isnanf(mathops::sqrt(-1)));
    }

    TEST_F(TranscedentalsTests, InvSqrtZero)
    {
        EXPECT_FLOAT_EQ(mathops::invsqrt(0), 1 / std::sqrt(0));
    }
    TEST_F(TranscedentalsTests, InvSqrtPerfect)
    {
        EXPECT_FLOAT_EQ(mathops::invsqrt(9), 1 / std::sqrt(9));
    }
    TEST_F(TranscedentalsTests, InvSqrtReal)
    {
        EXPECT_FLOAT_EQ(mathops::invsqrt(realNumber), 1 / std::sqrt(realNumber));
    }
    TEST_F(TranscedentalsTests, InvSqrtSmall)
    {
        EXPECT_FLOAT_EQ(mathops::invsqrt(smallNumber), 1 / std::sqrt(smallNumber));
    }
    TEST_F(TranscedentalsTests, InvSqrtNegative)
    {
        EXPECT_TRUE(isnanf(mathops::invsqrt(-1)));
    }

    TEST_F(TranscedentalsTests, FastSqrtZero)
    {
        EXPECT_NEAR(mathops::fast_sqrt(0), std::sqrt(0), 0.01 * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastSqrtPerfect)
    {
        float expected = std::sqrt(9);
        EXPECT_NEAR(mathops::fast_sqrt(9), expected,
            expected * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastSqrtReal)
    {
        float expected = std::sqrt(realNumber);
        EXPECT_NEAR(mathops::fast_sqrt(realNumber), expected,
            expected * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastSqrtSmall)
    {
        float expected = std::sqrt(smallNumber);
        EXPECT_NEAR(mathops::fast_sqrt(smallNumber), expected,
            expected * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastSqrtNegative)
    {
        EXPECT_TRUE(isnanf(mathops::fast_sqrt(-1)));
    }

    TEST_F(TranscedentalsTests, FastInvSqrtZero)
    {
        EXPECT_FLOAT_EQ(mathops::fast_invsqrt(0), 1 / std::sqrt(0));
    }
    TEST_F(TranscedentalsTests, FastInvSqrtPerfect)
    {
        float expected = 1 / std::sqrt(9);
        EXPECT_NEAR(mathops::fast_invsqrt(9), expected,
            expected * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastInvSqrtReal)
    {
        float expected = 1 / std::sqrt(realNumber);
        EXPECT_NEAR(mathops::fast_invsqrt(realNumber), expected,
            expected * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastInvSqrtSmall)
    {
        float expected = 1 / std::sqrt(smallNumber);
        EXPECT_NEAR(mathops::fast_invsqrt(smallNumber), expected,
            expected * maximalFastInvSqrtRelativeError);
    }
    TEST_F(TranscedentalsTests, FastInvSqrtNegative)
    {
        EXPECT_TRUE(isnanf(mathops::fast_invsqrt(-1)));
    }
} // tests
} // analysis