#include <simd/detail/vec/simd_vec2.hpp>
#include <simd/detail/vec/AVX/simd_vec2_avx_float.hpp>

#include <gtest/gtest.h>

#undef addv2f
#undef subv2f
#undef mulv2f
#undef divv2f
#undef dotv2f

namespace analysis
{
namespace tests
{
    TEST(FloatAvxVector2, VecAddPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        auto res = simd::avx::addv2f(vec1, vec2);

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

        auto res = simd::avx::addv2f(vec1, vec2);

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

        auto res = simd::avx::subv2f(vec1, vec2);

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

        auto res = simd::avx::subv2f(vec1, vec2);

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

        auto res = simd::avx::mulv2f(vec1, vec2);

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

        auto res = simd::avx::mulv2f(vec1, vec2);

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

        auto res = simd::avx::divv2f(vec1, vec2);

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

        auto res = simd::avx::divv2f(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatAvxVector2, VecDotPositive)
    {
        constexpr size_t vecLen = 2;
        float vec1Data[] = {4.1f, 4.2f};
        float vec2Data[] = {1.f, 4000000.1f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1]);

        float res = simd::avx::dotv2f(vec1, vec2);

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

        float res = simd::avx::dotv2f(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
}
}