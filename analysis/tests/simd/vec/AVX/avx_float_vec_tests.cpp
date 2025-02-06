#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/AVX/simd_vec_avx_float.hpp>

#include <cmath>

#include <gtest/gtest.h>

#undef addvf
#undef subvf
#undef mulvf
#undef divvf

#undef absvf
#undef minvf
#undef maxvf

#undef dotvf

namespace analysis
{
namespace tests
{
    TEST(FloatAvxVector, Vec4AddPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::avx::addvf(vec1, vec2);

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

        auto res = simd::avx::addvf(vec1, vec2);

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

        auto res = simd::avx::subvf(vec1, vec2);

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

        auto res = simd::avx::subvf(vec1, vec2);

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

        auto res = simd::avx::mulvf(vec1, vec2);

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

        auto res = simd::avx::mulvf(vec1, vec2);

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

        auto res = simd::avx::divvf(vec1, vec2);

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

        auto res = simd::avx::divvf(vec1, vec2);

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

        auto res = simd::avx::absvf(vec);

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

        auto res = simd::avx::absvf(vec);

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

        auto res = simd::avx::minvf(vec1, vec2);

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

        auto res = simd::avx::minvf(vec1, vec2);

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

        auto res = simd::avx::maxvf(vec1, vec2);

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

        auto res = simd::avx::maxvf(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], std::max(vec1Data[i], vec2Data[i]));
        }
    }
    
    TEST(FloatAvxVector, Vec4DotPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        float res = simd::avx::dotvf(vec1, vec2);

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

        float res = simd::avx::dotvf(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
}
}