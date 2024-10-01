#ifndef SUMS_TESTS_FIXTURE_HPP
#define SUMS_TESTS_FIXTURE_HPP

#include <mathops_shared_fields.hpp>
#include <common/memory_common.inl>
#include <mathops/mathops_tests_fixture.hpp>

#include <gtest/gtest.h>
#include <functional>
#include <cstddef>
#include <numeric> // std::inclusive_scan

namespace analysis
{
namespace tests
{
    class SumsTests : public MathopsTests
    {
    protected:
        void test_prefix_sum(std::function<void(const float *, size_t, float *)> testedPrefixSum,
            const float *arr, size_t size)
        {
            float* result = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);
            float* expected = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);

            testedPrefixSum(arr, size, result);
            std::inclusive_scan(arr, arr + size, expected);

            for (size_t i = 0; i < size; i++)
            {
                EXPECT_FLOAT_EQ(result[i], expected[i]);
            }

            _free_aligned_memory(result);
            _free_aligned_memory(expected);
        }
    };
} // namespace tests
} // namespace analysis

#endif // SUMS_TESTS_FIXTURE_HPP