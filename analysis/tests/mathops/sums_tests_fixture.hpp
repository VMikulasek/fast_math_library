#ifndef SUMS_TESTS_FIXTURE_HPP
#define SUMS_TESTS_FIXTURE_HPP

#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/mathops_tests_fixture.hpp>
#include <tests_common.hpp>

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
            test_arr_float_operation(testedPrefixSum, reference_prefix_sum, arr, size, 0, false);
        }
    };
} // namespace tests
} // namespace analysis

#endif // SUMS_TESTS_FIXTURE_HPP