#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/AVX/simd_vec3_avx_float.hpp>

#include <cmath>

#include <gtest/gtest.h>

#undef addv3f
#undef subv3f
#undef mulv3f
#undef divv3f

#undef absv3f
#undef minv3f
#undef maxv3f

#undef fast_sqrtv3f
#undef fast_invsqrtv3f

#undef fast_sinv3f
#undef fast_cosv3f
#undef crossv3f

#undef dotv3f
#undef lengthv3f
#undef normalizev3f

namespace analysis
{
namespace tests
{
    static constexpr float maximalFastInvSqrtRelativeError = 0.00175124;
    static constexpr float maximalSinCosAbsoluteError = 0.00048828128;

    TEST(FloatAvxVector3, VecAddPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::addv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecAddNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::addv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecSubPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::subv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecSubNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::subv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecMulPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::mulv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecMulNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::mulv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecDivPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::divv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatAvxVector3, VecDivNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::divv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }

    TEST(FloatAvxVector3, VecAbsPositive)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {4.1f, 4.2f, 4.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::absv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector3, VecAbsNegative)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {-123413.134f, -4591.13f, -1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1],
            vecData[2]);

        auto res = simd::avx::absv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector3, VecMinPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::minv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector3, VecMinNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::minv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector3, VecMaxPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::maxv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector3, VecMaxNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::maxv3f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }

    TEST(FloatAvxVector3, VecFastSqrt)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {0.1f, 4.2f, 4.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::fast_sqrtv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sqrt(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector3, VecFastInvSqrt)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {0.1f, 4.2f, 4.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::fast_invsqrtv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = 1 / std::sqrt(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector3, VecFastSinPositive)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {0.1f, 3.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::fast_sinv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sin(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector3, VecFastSinNegative)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {-1.134f, -3.13f, -1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::fast_sinv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sin(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector3, VecFastCosPositive)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {0.1f, 3.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::fast_cosv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cos(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector3, VecFastCosNegative)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {-1.134f, -3.13f, -1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::fast_cosv3f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cos(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector3, VecCrossPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        auto res = simd::avx::crossv3f(vec1, vec2);

        EXPECT_FLOAT_EQ(res.x, -17199981.95);
        EXPECT_FLOAT_EQ(res.y, -13.74);
        EXPECT_FLOAT_EQ(res.z, 16399996.21);
    }
    TEST(FloatAvxVector3, VecDotPositive)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {4.1f, 4.2f, 4.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        float res = simd::avx::dotv3f(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector3, VecDotNegative)
    {
        constexpr size_t vecLen = 3;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2]);

        float res = simd::avx::dotv3f(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector3, VecLengthPositive)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {0.1f, 3.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        float res = simd::avx::lengthv3f(vec);

        EXPECT_FLOAT_EQ(res, 4.38520238985614);
    }
    TEST(FloatAvxVector3, VecNormalizePositive)
    {
        constexpr size_t vecLen = 3;
        float vecData[] = {0.1f, 3.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2]);

        auto res = simd::avx::normalizev3f(vec);

        EXPECT_FLOAT_EQ(res.data[0], 0.022803964585835);
        EXPECT_FLOAT_EQ(res.data[1], 0.706922902160896);
        EXPECT_FLOAT_EQ(res.data[2], 0.706922902160896);
    }
}
}