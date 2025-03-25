#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/VEC/simd_vec2_vec.hpp>
#include <simd/simd_common.hpp>

#include <cmath>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    static constexpr float maximalFastInvSqrtRelativeError = 0.00175124;
    static constexpr float maximalSinCosAbsoluteError = 0.00048828128;

    TEST(FloatAvxVector2, VecAddPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::addv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecAddNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::addv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecSubPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::subv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecSubNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::subv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecMulPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::mulv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecMulNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::mulv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecDivPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::divv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecDivNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::divv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }

    TEST(FloatAvxVector2, VecAbsPositive)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {4.1f, 4.2f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::absv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector2, VecAbsNegative)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {-123413.134f, -4591.13f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::absv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector2, VecMinPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::minv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector2, VecMinNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::minv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector2, VecMaxPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::maxv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector2, VecMaxNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::maxv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }

    TEST(FloatAvxVector2, VecFastSqrt)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {0.1f, 4.2f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::fast_sqrtv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sqrt(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector2, VecFastInvSqrt)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {0.1f, 4.2f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::fast_invsqrtv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = 1 / std::sqrt(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector2, VecFastSinPositive)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {0.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::fast_sinv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sin(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector2, VecFastSinNegative)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {-1.134f, -3.13f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::fast_sinv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sin(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector2, VecFastCosPositive)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {0.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::fast_cosv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cos(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector2, VecFastCosNegative)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {-1.134f, -3.13f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::fast_cosv2v<float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cos(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector2, VecDotPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        float res = simd::avx::dotv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector2, VecDotNegative)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {-123413.134f, -4591.13f};
        float vec2Data[] = {-111.f, -4562431.13f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        float res = simd::avx::dotv2v<float, simd::InstructionSet::AVX>(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector2, VecLengthPositive)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {0.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        float res = simd::avx::lengthv2v<float, simd::InstructionSet::AVX>(vec);

        EXPECT_FLOAT_EQ(res, 3.101612483854165);
    }
    TEST(FloatAvxVector2, VecNormalizePositive)
    {
        constexpr size_t vecLen = 2;
        float vecData[] = {0.1f, 3.1f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1]);

        auto res = simd::avx::normalizev2v<float, simd::InstructionSet::AVX>(vec);

        EXPECT_FLOAT_EQ(res.data[0], 0.032241294010958);
        EXPECT_FLOAT_EQ(res.data[1], 0.9994801143397);
    }
}
}