#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

#include <gtest/gtest.h>

#undef addv
#undef subv
#undef mulv
#undef divv
#undef dotv

namespace analysis
{
namespace tests
{
    TEST(FloatSeqVector, Vec4AddPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::addv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec9AddNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::addv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec4SubPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::subv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec9SubNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::subv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec4MulPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::mulv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec9MulNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::mulv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec4DivPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::divv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec9DivNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::divv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_FLOAT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(FloatSeqVector, Vec4DotPositive)
    {
        constexpr size_t vecLen = 4;
        float vec1Data[] = {4.1f, 4.2f, 4.3f, 2.3f};
        float vec2Data[] = {1.f, 4000000.1f, 4.4f, 2.2f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        float res = simd::seq::dotv(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
    TEST(FloatSeqVector, Vec9DotNegative)
    {
        constexpr size_t vecLen = 9;
        float vec1Data[] = {-123413.134f, -4591.13f, -1.f, -3.f, -131.13f, -111.111f, -1.f, -1.f, -1213.f};
        float vec2Data[] = {-111.f, -4562431.13f, -1.f, -13531.f, -1.f, -1.f, -1.f, -1.f, -1.f};

        auto vec1 = simd::Vec<vecLen, float>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, float>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        float res = simd::seq::dotv(vec1, vec2);

        float expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_FLOAT_EQ(res, expected);
    }
}
}