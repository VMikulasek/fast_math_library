#include <simd/detail/vec/simd_vec4.hpp>
#include <simd/detail/vec/AVX/simd_vec4_avx_float.hpp>

#include <cmath>

#include <gtest/gtest.h>

#undef addv4f
#undef subv4f
#undef mulv4f
#undef divv4f

#undef absv4f
#undef minv4f
#undef maxv4f

#undef fast_sqrtv4f
#undef fast_invsqrtv4f

#undef fast_sinv4f
#undef fast_cosv4f

#undef dotv4f
#undef lengthv4f
#undef normalizev4f

namespace analysis
{
namespace tests
{
    static constexpr float maximalFastInvSqrtRelativeError = 0.00175124;
    static constexpr float maximalSinCosAbsoluteError = 0.00048828128;

    TEST(FloatAvxVector4, VecAddPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::addv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecAddNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::addv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecSubPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::subv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecSubNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::subv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecMulPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::mulv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecMulNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::mulv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecDivPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::divv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatAvxVector4, VecDivNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::divv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }

    TEST(FloatAvxVector4, VecAbsPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {4.1f, 4.2f, 4.3f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::absv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector4, VecAbsNegative)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {-123413.134f, -4591.13f, -1.f, -3.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1],
            vecData[2], vecData[3]);

        auto res = simd::avx::absv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector4, VecMinPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::minv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector4, VecMinNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::minv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector4, VecMaxPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::maxv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector4, VecMaxNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::maxv4f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }

    TEST(FloatAvxVector4, VecFastSqrt)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 4.2f, 4.3f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::fast_sqrtv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sqrtf(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector4, VecFastInvSqrt)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 4.2f, 4.3f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::fast_invsqrtv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = 1 / std::sqrtf(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector4, VecFastSinPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::fast_sinv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sinf(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector4, VecFastSinNegative)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {-1.134f, -3.13f, -1.f, -3.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::fast_sinv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sinf(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector4, VecFastCosPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::fast_cosv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cosf(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector4, VecFastCosNegative)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {-1.134f, -3.13f, -1.f, -3.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::fast_cosv4f(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cosf(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector4, VecDotPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        float res = simd::avx::dotv4f(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector4, VecDotNegative)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        float res = simd::avx::dotv4f(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector4, VecLengthPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        float res = simd::avx::lengthv4f(vec);

        EXPECT_FLOAT_EQ(res, 4.951767361255979);
    }
    TEST(FloatAvxVector4, VecNormalizePositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::avx::normalizev4f(vec);

        EXPECT_FLOAT_EQ(res.data[0], 0.02019480979305);
        EXPECT_FLOAT_EQ(res.data[1], 0.626039103584565);
        EXPECT_FLOAT_EQ(res.data[2], 0.626039103584565);
        EXPECT_FLOAT_EQ(res.data[3], 0.464480625240161);
    }
}
}