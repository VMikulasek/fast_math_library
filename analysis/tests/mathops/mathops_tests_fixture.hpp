#ifndef MATHOPS_TESTS_FIXTURE_HPP
#define MATHOPS_TESTS_FIXTURE_HPP

#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    class MathopsTests : public testing::Test
    {
    private:
        bool _bigArrTest;

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
            const float *arr, size_t size, float maximalRelativeError)
        {
            float* result = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);
            float* expected = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);

            testedArrOperation(arr, size, result);
            referenceArrOperation(arr, size, expected);

            for (size_t i = 0; i < size; i++)
            {
                if (maximalRelativeError == 0)
                {
                    EXPECT_FLOAT_EQ(result[i], expected[i]);
                }
                else
                {
                    EXPECT_NEAR(result[i], expected[i], (expected[i] == 0 ? 0.01 : expected[i]) * maximalRelativeError);
                }
            }

            _free_aligned_memory(result);
            _free_aligned_memory(expected);
        }
    };
} // namespace tests
} // namespace analysis

#endif // MATHOPS_TESTS_FIXTURE_HPP