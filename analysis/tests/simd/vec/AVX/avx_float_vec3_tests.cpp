#include <simd/detail/vec/simd_vec3.hpp>
#include <simd/detail/vec/AVX/simd_vec3_avx_float.hpp>

#include <cmath>

#include <gtest/gtest.h>

#undef addv3f
#undef subv3f
#undef mulv3f
#undef divv3f

#undef absv3f

#undef dotv3f

namespace analysis
{
namespace tests
{
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
}
}