#include <simd/detail/vec/simd_vec_t.hpp>
#include <simd/detail/vec/SEQ/simd_vec_seq.hpp>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    TEST(IntSeqVector, Vec4AddPositive)
    {
        constexpr size_t vecLen = 4;
        int vec1Data[] = {4, 4, 4, 2};
        int vec2Data[] = {1, 4000000, 4, 2};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::addv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec9AddNegative)
    {
        constexpr size_t vecLen = 9;
        int vec1Data[] = {-123413, -4591, -1, -3, -131, -111, -1, -1, -1213};
        int vec2Data[] = {-111, -4562431, -1, -13531, -1, -1, -1, -1, -1};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::addv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] + vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec4SubPositive)
    {
        constexpr size_t vecLen = 4;
        int vec1Data[] = {4, 4, 4, 2};
        int vec2Data[] = {1, 4000000, 4, 2};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::subv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec9SubNegative)
    {
        constexpr size_t vecLen = 9;
        int vec1Data[] = {-123413, -4591, -1, -3, -131, -111, -1, -1, -1213};
        int vec2Data[] = {-111, -4562431, -1, -13531, -1, -1, -1, -1, -1};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::subv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] - vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec4MulPositive)
    {
        constexpr size_t vecLen = 4;
        int vec1Data[] = {4, 4, 4, 2};
        int vec2Data[] = {1, 4000000, 4, 2};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::mulv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec9MulNegative)
    {
        constexpr size_t vecLen = 9;
        int vec1Data[] = {-123413, -4591, -1, -3, -131, -111, -1, -1, -1213};
        int vec2Data[] = {-111, -4562431, -1, -13531, -1, -1, -1, -1, -1};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::mulv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] * vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec4DivPositive)
    {
        constexpr size_t vecLen = 4;
        int vec1Data[] = {4, 4, 4, 2};
        int vec2Data[] = {1, 4000000, 4, 2};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        auto res = simd::seq::divv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec9DivNegative)
    {
        constexpr size_t vecLen = 9;
        int vec1Data[] = {-123413, -4591, -1, -3, -131, -111, -1, -1, -1213};
        int vec2Data[] = {-111, -4562431, -1, -13531, -1, -1, -1, -1, -1};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        auto res = simd::seq::divv(vec1, vec2);

        for (size_t i = 0; i < vecLen; i++)
        {
            EXPECT_EQ(res.data[i], vec1Data[i] / vec2Data[i]);
        }
    }
    TEST(IntSeqVector, Vec4DotPositive)
    {
        constexpr size_t vecLen = 4;
        int vec1Data[] = {4, 4, 4, 2};
        int vec2Data[] = {1, 1, 4, 2};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3]);

        int res = simd::seq::dotv(vec1, vec2);

        int expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_EQ(res, expected);
    }
    TEST(IntSeqVector, Vec9DotNegative)
    {
        constexpr size_t vecLen = 9;
        int vec1Data[] = {-123413, -4591, -1, -3, -131, -111, -1, -1, -1213};
        int vec2Data[] = {-111, -4562431, -1, -13531, -1, -1, -1, -1, -1};

        auto vec1 = simd::Vec<vecLen, int>(vec1Data[0], vec1Data[1], vec1Data[2], vec1Data[3], vec1Data[4],
            vec1Data[5], vec1Data[6], vec1Data[7], vec1Data[8]);
        auto vec2 = simd::Vec<vecLen, int>(vec2Data[0], vec2Data[1], vec2Data[2], vec2Data[3], vec2Data[4],
            vec2Data[5], vec2Data[6], vec2Data[7], vec2Data[8]);

        int res = simd::seq::dotv(vec1, vec2);

        int expected = 0;
        for (size_t i = 0; i < vecLen; i++)
        {
            expected += vec1Data[i] * vec2Data[i];
        }

        EXPECT_EQ(res, expected);
    }
}
}