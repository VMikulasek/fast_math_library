#ifndef SUMS_TESTS_FIXTURE_HPP
#define SUMS_TESTS_FIXTURE_HPP

#include <simd/simd_common.hpp>
#include <sums_shared_fields.hpp>

#include <gtest/gtest.h>
#include <string>
#include <functional>
#include <cstddef>
#include <numeric> // std::inclusive_scan

namespace analysis
{
namespace tests
{
    class SumsTests : public testing::Test
    {
    private:
        bool _bigArrTest;

    protected:
        float *_bigArr;

        SumsTests()
        {
            std::string testName = testing::UnitTest::GetInstance()->current_test_info()->name();
            _bigArrTest = testName.find("Big") != std::string::npos;

            if (_bigArrTest)
            {
                _bigArr = AllocBigArr();
            }
        }

        ~SumsTests()
        {
            if (_bigArrTest)
            {
                FreeBigArr(_bigArr);
            }
        }

        void test_prefix_sum(std::function<void(const float *, size_t, float *)> testedPrefixSum,
            const float *arr, size_t size)
        {
#if defined(_MSC_VER)
            float* result = static_cast<float*>(_aligned_malloc(size * sizeof(float), AVX_ALIGNMENT));
            float* expected = static_cast<float*>(_aligned_malloc(size * sizeof(float), AVX_ALIGNMENT));
#else // _MSC_VER
            float* result = static_cast<float*>(std::aligned_alloc(AVX_ALIGNMENT, size * sizeof(float)));
            float* expected = static_cast<float*>(std::aligned_alloc(AVX_ALIGNMENT, size * sizeof(float)));
#endif // _MSC_VER

            testedPrefixSum(arr, size, result);
            std::inclusive_scan(arr, arr + size, expected);

            for (size_t i = 0; i < size; i++)
            {
                EXPECT_FLOAT_EQ(result[i], expected[i]);
            }

#if defined(_MSC_VER)
            _aligned_free(result);
            _aligned_free(expected);
#else // _MSC_VER
            std::free(result);
            std::free(expected);
#endif // _MSC_VER
        }
    };
} // namespace tests
} // namespace analysis

#endif // SUMS_TESTS_FIXTURE_HPP