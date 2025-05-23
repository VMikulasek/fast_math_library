#ifdef HAS_AVX

#include <mathops/sums_tests_fixture.hpp>
#include <mathops/detail/VEC/vec_sums.hpp>
#include <simd/simd_common.hpp>

#include <gtest/gtest.h>
#include <numeric> // std::reduce

namespace analysis
{
namespace tests
{
    class AvxSumsTests : public SumsTests
    {
    protected:
        void test_prefix_sum(const float *arr, size_t size)
        {
            SumsTests::test_prefix_sum(mathops::vec::prefix_sum<float, simd::InstructionSet::AVX>, arr, size);
        }
    };

    TEST_F(AvxSumsTests, Sum1ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_1ElemArr, _1_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_1ElemArr, _1ElemArr + _1_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum8ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_8ElemArr, _8_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_8ElemArr, _8ElemArr + _8_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum9ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_9ElemArr, _9_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_9ElemArr, _9ElemArr + _9_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum16ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_16ElemArr, _16_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_16ElemArr, _16ElemArr + _16_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum17ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_17ElemArr, _17_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_17ElemArr, _17ElemArr + _17_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum24ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_24ElemArr, _24_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_24ElemArr, _24ElemArr + _24_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, Sum25ElemArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_25ElemArr, _25_ELEM_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_25ElemArr, _25ElemArr + _25_ELEM_ARR_SIZE, 0.0f));
    }
    TEST_F(AvxSumsTests, SumBigArr)
    {
        auto res = mathops::vec::sum<float, simd::InstructionSet::AVX>(_bigArr, BIG_ARR_SIZE);
        EXPECT_FLOAT_EQ(res, std::reduce(_bigArr, _bigArr + BIG_ARR_SIZE, 0.0f));
    }

    TEST_F(AvxSumsTests, PrefixSum1ElemArr)
    {
        test_prefix_sum(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum8ElemArr)
    {
        test_prefix_sum(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum9ElemArr)
    {
        test_prefix_sum(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum16ElemArr)
    {
        test_prefix_sum(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum17ElemArr)
    {
        test_prefix_sum(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum24ElemArr)
    {
        test_prefix_sum(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSum25ElemArr)
    {
        test_prefix_sum(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxSumsTests, PrefixSumBigArr)
    {
        test_prefix_sum(_bigArr, BIG_ARR_SIZE);
    }
} // namespace tests
} // namespace analysis

#endif // HAS_AVX