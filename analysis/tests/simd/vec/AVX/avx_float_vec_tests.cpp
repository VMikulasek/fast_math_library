#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/VEC/simd_vec_vec.hpp>

#include <cmath>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    static constexpr float maximalFastInvSqrtRelativeError = 0.00175124;
    static constexpr float maximalSinCosAbsoluteError = 0.00048828128;

#if defined(HAS_AVX)

    TEST(FloatAvxVector, Vec4AddPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::vec::addv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec9AddNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::vec::addv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec4SubPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::vec::subv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec9SubNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::vec::subv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec4MulPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::vec::mulv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec9MulNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::vec::mulv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec4DivPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::vec::divv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatAvxVector, Vec9DivNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::vec::divv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    
    TEST(FloatAvxVector, Vec4AbsPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {4.1f, 4.2f, 4.3f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::vec::absv<vecLen, float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector, Vec9AbsNegative)
    {
        constexpr size_t vecLen = 9;
        float vecData[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3], vecData[4],
            vecData[5], vecData[6], vecData[7], vecData[8]);

        auto res = simd::vec::absv<vecLen, float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], abs(vecData[i]));
        }
    }
    TEST(FloatAvxVector, Vec4MinPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::vec::minv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector, Vec9MinNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::vec::minv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::min(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector, Vec4MaxPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::vec::maxv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }
    TEST(FloatAvxVector, Vec9MaxNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::vec::maxv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }

#if defined(HAS_AVX2)

    TEST(FloatAvxVector, Vec9FastSqrt)
    {
        constexpr size_t vecLen = 9;
        float vecData[] = {0.1f, 4.2f, 4.3f, 2.3f, 999.9f, 134135.f, 2.f, 3581.13514f, 1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3],
            vecData[4], vecData[5], vecData[6], vecData[7], vecData[8]);

        auto res = simd::vec::fast_sqrtv<vecLen, float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sqrt(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector, Vec9FastInvSqrt)
    {
        constexpr size_t vecLen = 9;
        float vecData[] = {0.1f, 4.2f, 4.3f, 2.3f, 999.9f, 134135.f, 2.f, 3581.13514f, 1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3],
            vecData[4], vecData[5], vecData[6], vecData[7], vecData[8]);

        auto res = simd::vec::fast_invsqrtv<vecLen, float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = 1 / std::sqrt(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalFastInvSqrtRelativeError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

#endif // HAS_AVX2
    
    TEST(FloatAvxVector, Vec4FastSinPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::vec::fast_sinv<vecLen, float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sin(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector, Vec9FastSinNegative)
    {
        constexpr size_t vecLen = 9;
        float vecData[] = {-1.134f, -3.13f, -1.f, -3.f, -1.13f, -1.111f, -1.f, -1.f, -1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3], vecData[4],
            vecData[5], vecData[6], vecData[7], vecData[8]);

        auto res = simd::vec::fast_sinv<vecLen, float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::sin(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector, Vec4FastCosPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::vec::fast_cosv<vecLen, float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cos(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }
    TEST(FloatAvxVector, Vec9FastCosNegative)
    {
        constexpr size_t vecLen = 9;
        float vecData[] = {-1.134f, -3.13f, -1.f, -3.f, -1.13f, -1.111f, -1.f, -1.f, -1.f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3], vecData[4],
            vecData[5], vecData[6], vecData[7], vecData[8]);

        auto res = simd::vec::fast_cosv<vecLen, float, simd::InstructionSet::AVX>(vec);

        for (size_t i = 0; i < vecLen; i++)
        {
            float expected = std::cos(vecData[i]);
            EXPECT_NEAR(res.data[i], expected, maximalSinCosAbsoluteError * std::abs(expected == 0 ? 0.1 : expected));
        }
    }

    TEST(FloatAvxVector, Vec4DotPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        float res = simd::vec::dotv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector, Vec9DotNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        float res = simd::vec::dotv<vecLen, float, simd::InstructionSet::AVX>(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatAvxVector, Vec4LengthPositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        float res = simd::vec::lengthv<vecLen, float, simd::InstructionSet::AVX>(vec);

        EXPECT_FLOAT_EQ(res, 4.951767361255979);
    }
    TEST(FloatAvxVector, Vec4NormalizePositive)
    {
        constexpr size_t vecLen = 4;
        float vecData[] = {0.1f, 3.1f, 3.1f, 2.3f};

        auto vec = simd::Vec<vecLen, float>(vecData[0], vecData[1], vecData[2], vecData[3]);

        auto res = simd::vec::normalizev<vecLen, float, simd::InstructionSet::AVX>(vec);

        EXPECT_FLOAT_EQ(res.data[0], 0.02019480979305);
        EXPECT_FLOAT_EQ(res.data[1], 0.626039103584565);
        EXPECT_FLOAT_EQ(res.data[2], 0.626039103584565);
        EXPECT_FLOAT_EQ(res.data[3], 0.464480625240161);
    }
}

#endif // HAS_AVX
}