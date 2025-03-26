#include <mathops/transcendentals_tests_fixture.hpp>
#include <mathops/detail/VEC/vec_transcendentals.hpp>
#include <mathops_shared_fields.hpp>
#include <simd/simd_common.hpp>

#include <gtest/gtest.h>
#include <cstddef>

namespace analysis
{
namespace tests
{
    class AvxTranscedentalsTests : public TranscedentalsTests
    {
    protected:
        void test_sqrt_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_sqrt_arr(mathops::vec::fast_sqrt_arr<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>,
                arr, size);
        }

        void test_invsqrt_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_invsqrt_arr(mathops::vec::fast_invsqrt_arr<float, simd::InstructionSet::AVX, simd::InstructionSet::AVX2>,
                arr, size);
        }

        void test_sin_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_sin_arr(mathops::vec::fast_sin_arr<float, simd::InstructionSet::AVX>,
                arr, size);
        }

        void test_cos_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_cos_arr(mathops::vec::fast_cos_arr<float, simd::InstructionSet::AVX>,
                arr, size);
        }
    };

    TEST_F(AvxTranscedentalsTests, FastSqrtArr1ElemArr)
    {
        test_sqrt_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArr8ElemArr)
    {
        test_sqrt_arr(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArr9ElemArr)
    {
        test_sqrt_arr(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArr16ElemArr)
    {
        test_sqrt_arr(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArr17ElemArr)
    {
        test_sqrt_arr(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArr24ElemArr)
    {
        test_sqrt_arr(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArr25ElemArr)
    {
        test_sqrt_arr(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSqrtArrBigArr)
    {
        test_sqrt_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr1ElemArr)
    {
        test_invsqrt_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr8ElemArr)
    {
        test_invsqrt_arr(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr9ElemArr)
    {
        test_invsqrt_arr(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr16ElemArr)
    {
        test_invsqrt_arr(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr17ElemArr)
    {
        test_invsqrt_arr(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr24ElemArr)
    {
        test_invsqrt_arr(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArr25ElemArr)
    {
        test_invsqrt_arr(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastInvSqrtArrBigArr)
    {
        test_invsqrt_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(AvxTranscedentalsTests, FastSinArr1ElemArr)
    {
        test_sin_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArr8ElemArr)
    {
        test_sin_arr(_8ElemArrMinusPiPi, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArr9ElemArr)
    {
        test_sin_arr(_9ElemArrMinusPiPi, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArr16ElemArr)
    {
        test_sin_arr(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArr17ElemArr)
    {
        test_sin_arr(_17ElemArrMinusPiPi, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArr24ElemArr)
    {
        test_sin_arr(_24ElemArrMinusPiPi, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArr25ElemArr)
    {
        test_sin_arr(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastSinArrBigArr)
    {
        test_sin_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(AvxTranscedentalsTests, FastCosArr1ElemArr)
    {
        test_cos_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArr8ElemArr)
    {
        test_cos_arr(_8ElemArrMinusPiPi, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArr9ElemArr)
    {
        test_cos_arr(_9ElemArrMinusPiPi, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArr16ElemArr)
    {
        test_cos_arr(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArr17ElemArr)
    {
        test_cos_arr(_17ElemArrMinusPiPi, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArr24ElemArr)
    {
        test_cos_arr(_24ElemArrMinusPiPi, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArr25ElemArr)
    {
        test_cos_arr(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, FastCosArrBigArr)
    {
        test_cos_arr(_bigArr, BIG_ARR_SIZE);
    }
} // namespace tests
} // namespace analysis