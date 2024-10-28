#include <mathops/transcedentals_tests_fixture.hpp>
#include <mathops/transcedentals.hpp>

#include <gtest/gtest.h>
#include <numbers>

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

    TEST_F(TranscedentalsTests, SinZero)
    {
        EXPECT_FLOAT_EQ(mathops::sin(0), std::sin(0));
    }
    TEST_F(TranscedentalsTests, SinReal)
    {
        EXPECT_FLOAT_EQ(mathops::sin(realNumber), std::sin(realNumber));
    }
    TEST_F(TranscedentalsTests, SinSmall)
    {
        EXPECT_FLOAT_EQ(mathops::sin(smallNumber), std::sin(smallNumber));
    }
    TEST_F(TranscedentalsTests, SinNegative)
    {
        EXPECT_FLOAT_EQ(mathops::sin(-1), std::sin(-1));
    }

    TEST_F(TranscedentalsTests, CosZero)
    {
        EXPECT_FLOAT_EQ(mathops::cos(0), std::cos(0));
    }
    TEST_F(TranscedentalsTests, CosReal)
    {
        EXPECT_FLOAT_EQ(mathops::cos(realNumber), std::cos(realNumber));
    }
    TEST_F(TranscedentalsTests, CosSmall)
    {
        EXPECT_FLOAT_EQ(mathops::cos(smallNumber), std::cos(smallNumber));
    }
    TEST_F(TranscedentalsTests, CosNegative)
    {
        EXPECT_FLOAT_EQ(mathops::cos(-1), std::cos(-1));
    }

    TEST_F(TranscedentalsTests, FastSinZero)
    {
        EXPECT_NEAR(mathops::fast_sin(0), std::sin(0), maximalSinCosAbsoluteError);
    }
    TEST_F(TranscedentalsTests, FastSinReal)
    {
        EXPECT_NEAR(mathops::fast_sin(smallRealNegNumber), std::sin(smallRealNegNumber), maximalSinCosAbsoluteError);
    }
    TEST_F(TranscedentalsTests, FastSinSmall)
    {
        EXPECT_NEAR(mathops::fast_sin(smallNumber), std::sin(smallNumber), maximalSinCosAbsoluteError);
    }
    TEST_F(TranscedentalsTests, FastSinNegative)
    {
        EXPECT_NEAR(mathops::fast_sin(-1), std::sin(-1), maximalSinCosAbsoluteError);
    }

    TEST_F(TranscedentalsTests, FastCosZero)
    {
        EXPECT_NEAR(mathops::fast_cos(0), std::cos(0), maximalSinCosAbsoluteError);
    }
    TEST_F(TranscedentalsTests, FastCosReal)
    {
        EXPECT_NEAR(mathops::fast_cos(smallRealNegNumber), std::cos(smallRealNegNumber), maximalSinCosAbsoluteError);
    }
    TEST_F(TranscedentalsTests, FastCosSmall)
    {
        EXPECT_NEAR(mathops::fast_cos(smallNumber), std::cos(smallNumber), maximalSinCosAbsoluteError);
    }
    TEST_F(TranscedentalsTests, FastCosNegative)
    {
        EXPECT_NEAR(mathops::fast_cos(-1), std::cos(-1), maximalSinCosAbsoluteError);
    }

    TEST_F(TranscedentalsTests, TanZero)
    {
        EXPECT_FLOAT_EQ(mathops::tan(0), std::tan(0));
    }
    TEST_F(TranscedentalsTests, TanPi2)
    {
        float num = std::numbers::pi / 2.f;
        EXPECT_FLOAT_EQ(mathops::tan(num), std::tan(num));
    }
    TEST_F(TranscedentalsTests, TanReal)
    {
        EXPECT_FLOAT_EQ(mathops::tan(realNumber), std::tan(realNumber));
    }
    TEST_F(TranscedentalsTests, TanSmall)
    {
        EXPECT_FLOAT_EQ(mathops::tan(smallNumber), std::tan(smallNumber));
    }
    TEST_F(TranscedentalsTests, TanNegative)
    {
        EXPECT_FLOAT_EQ(mathops::tan(-1), std::tan(-1));
    }
    
    TEST_F(TranscedentalsTests, CotZero)
    {
        EXPECT_FLOAT_EQ(mathops::cot(0), 1 / std::tan(0));
    }
    TEST_F(TranscedentalsTests, CotPi2)
    {
        float num = std::numbers::pi / 2.f;
        EXPECT_FLOAT_EQ(mathops::cot(num), 1 / std::tan(num));
    }
    TEST_F(TranscedentalsTests, CotReal)
    {
        EXPECT_FLOAT_EQ(mathops::cot(realNumber), 1 / std::tan(realNumber));
    }
    TEST_F(TranscedentalsTests, CotSmall)
    {
        EXPECT_FLOAT_EQ(mathops::cot(smallNumber), 1 / std::tan(smallNumber));
    }
    TEST_F(TranscedentalsTests, CotNegative)
    {
        EXPECT_FLOAT_EQ(mathops::cot(-1), 1 / std::tan(-1));
    }
} // tests
} // analysis