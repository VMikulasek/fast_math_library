#ifndef MATHOPS_TESTS_FIXTURE_HPP
#define MATHOPS_TESTS_FIXTURE_HPP

#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_common.hpp>
#include <simd/simd_operations.hpp>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    class MathopsTests : public testing::Test
    {
    private:
        bool _bigArrTest;

        using FloatAvxOps = simd::SIMDOperations<float, simd::InstructionSet::AVX>;

    protected:
        float *_bigArr;

        MathopsTests()
        {
            std::string testName = testing::UnitTest::GetInstance()->current_test_info()->name();
            _bigArrTest = testName.find("Big") != std::string::npos;

            if (_bigArrTest)
            {
                _bigArr = AllocBigArr();
            }
        }

        ~MathopsTests()
        {
            if (_bigArrTest)
            {
                _free_aligned_memory(_bigArr);
            }
        }

        void test_arr_float_operation(std::function<void(const float *, size_t, float *)> testedArrOperation,
            std::function<void(const float *, size_t, float *)>referenceArrOperation ,
            const float *arr, size_t size, float maximalError, bool relativeError)
        {
            float* result = _alloc_aligned_memory_float(size * sizeof(float), FloatAvxOps::ALIGNMENT);
            float* expected = _alloc_aligned_memory_float(size * sizeof(float), FloatAvxOps::ALIGNMENT);

            testedArrOperation(arr, size, result);
            referenceArrOperation(arr, size, expected);

            for (size_t i = 0; i < size; i++)
            {
                if (maximalError == 0)
                {
                    EXPECT_FLOAT_EQ(result[i], expected[i]);
                }
                else
                {
                    float resMaximalError = maximalError;
                    if (relativeError)
                    {
                        resMaximalError = ((expected[i] == 0) ? 0.01f : expected[i]) * maximalError;
                    }
                    EXPECT_NEAR(result[i], expected[i], resMaximalError);
                }
            }

            _free_aligned_memory(result);
            _free_aligned_memory(expected);
        }
    };
} // namespace tests
} // namespace analysis

#endif // MATHOPS_TESTS_FIXTURE_HPP