#include <mathops/transcedentals_tests_fixture.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops_shared_fields.hpp>

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
            TranscedentalsTests::test_sqrt_arr(mathops::avx::fast_sqrt_arr,
                arr, size);
        }

        void test_invsqrt_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_invsqrt_arr(mathops::avx::fast_invsqrt_arr,
                arr, size);
        }

        void test_sin_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_sin_arr(mathops::avx::fast_sin_arr,
                arr, size);
        }

        void test_cos_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_cos_arr(mathops::avx::fast_cos_arr,
                arr, size);
        }
    };

    TEST_F(AvxTranscedentalsTests, SqrtArr1ElemArr)
    {
        test_sqrt_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArr8ElemArr)
    {
        test_sqrt_arr(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArr9ElemArr)
    {
        test_sqrt_arr(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArr16ElemArr)
    {
        test_sqrt_arr(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArr17ElemArr)
    {
        test_sqrt_arr(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArr24ElemArr)
    {
        test_sqrt_arr(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArr25ElemArr)
    {
        test_sqrt_arr(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SqrtArrBigArr)
    {
        test_sqrt_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(AvxTranscedentalsTests, InvSqrtArr1ElemArr)
    {
        test_invsqrt_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArr8ElemArr)
    {
        test_invsqrt_arr(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArr9ElemArr)
    {
        test_invsqrt_arr(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArr16ElemArr)
    {
        test_invsqrt_arr(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArr17ElemArr)
    {
        test_invsqrt_arr(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArr24ElemArr)
    {
        test_invsqrt_arr(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArr25ElemArr)
    {
        test_invsqrt_arr(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, InvSqrtArrBigArr)
    {
        test_invsqrt_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(AvxTranscedentalsTests, SinArr1ElemArr)
    {
        test_sin_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArr8ElemArr)
    {
        test_sin_arr(_8ElemArrMinusPiPi, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArr9ElemArr)
    {
        test_sin_arr(_9ElemArrMinusPiPi, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArr16ElemArr)
    {
        test_sin_arr(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArr17ElemArr)
    {
        test_sin_arr(_17ElemArrMinusPiPi, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArr24ElemArr)
    {
        test_sin_arr(_24ElemArrMinusPiPi, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArr25ElemArr)
    {
        test_sin_arr(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, SinArrBigArr)
    {
        test_sin_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(AvxTranscedentalsTests, CosArr1ElemArr)
    {
        test_cos_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArr8ElemArr)
    {
        test_cos_arr(_8ElemArrMinusPiPi, _8_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArr9ElemArr)
    {
        test_cos_arr(_9ElemArrMinusPiPi, _9_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArr16ElemArr)
    {
        test_cos_arr(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArr17ElemArr)
    {
        test_cos_arr(_17ElemArrMinusPiPi, _17_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArr24ElemArr)
    {
        test_cos_arr(_24ElemArrMinusPiPi, _24_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArr25ElemArr)
    {
        test_cos_arr(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
    }
    TEST_F(AvxTranscedentalsTests, CosArrBigArr)
    {
        test_cos_arr(_bigArr, BIG_ARR_SIZE);
    }
} // namespace tests
} // namespace analysis