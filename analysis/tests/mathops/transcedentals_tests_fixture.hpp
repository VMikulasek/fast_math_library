#ifndef SUMS_TESTS_FIXTURE_HPP
#define SUMS_TESTS_FIXTURE_HPP

#include <mathops_shared_fields.hpp>
#include <common/detail/memory_common.inl>
#include <mathops/mathops_tests_fixture.hpp>
#include <tests_common.hpp>

#include <gtest/gtest.h>
#include <functional>
#include <cstddef>

namespace analysis
{
namespace tests
{
    class TranscedentalsTests : public MathopsTests
    {
    protected:
        static constexpr float realNumber = 123456789.12;
        static constexpr float smallNumber = 0.25;
        static constexpr float maximalFastInvSqrtRelativeError = 0.00175124;
        static constexpr float maximalSinCosAbsoluteError = 0.00048828128;
        static constexpr float smallRealNegNumber = -2.13454;

        void test_sqrt_arr(std::function<void(const float *, size_t, float *)> testedSqrtArr,
            const float *arr, size_t size)
        {
            test_arr_float_operation(testedSqrtArr, reference_sqrt_arr, arr, size, maximalFastInvSqrtRelativeError, true);
        }

        void test_invsqrt_arr(std::function<void(const float *, size_t, float *)> testedInvSqrtArr,
            const float *arr, size_t size)
        {
            test_arr_float_operation(testedInvSqrtArr, reference_invsqrt_arr, arr, size, maximalFastInvSqrtRelativeError, true);
        }

        void test_sin_arr(std::function<void(const float*, size_t, float *)> testedSinArr,
            const float *arr, size_t size)
        {
            test_arr_float_operation(testedSinArr, reference_sin_arr, arr, size, maximalSinCosAbsoluteError, false);
        }

        void test_cos_arr(std::function<void(const float*, size_t, float *)> testedCosArr,
            const float *arr, size_t size)
        {
            test_arr_float_operation(testedCosArr, reference_cos_arr, arr, size, maximalSinCosAbsoluteError, false);
        }

        void test_tan_arr(std::function<void(const float*, size_t, float *)> testedCosArr,
            const float *arr, size_t size)
        {
            test_arr_float_operation(testedCosArr, reference_tan_arr, arr, size, maximalSinCosAbsoluteError, false);
        }

        void test_cot_arr(std::function<void(const float*, size_t, float *)> testedCosArr,
            const float *arr, size_t size)
        {
            test_arr_float_operation(testedCosArr, reference_cot_arr, arr, size, maximalSinCosAbsoluteError, false);
        }
    };
} // namespace tests
} // namespace analysis

#endif // SUMS_TESTS_FIXTURE_HPP