#include <mathops/transcendentals_tests_fixture.hpp>
#include <mathops/detail/SEQ/seq_transcendentals.hpp>
#include <mathops_shared_fields.hpp>

#include <gtest/gtest.h>
#include <cstddef>

namespace analysis
{
namespace tests
{
    class SeqTranscedentalsTests : public TranscedentalsTests
    {
    protected:
        void test_sqrt_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_sqrt_arr(mathops::seq::fast_sqrt_arr<float>,
                arr, size);
        }

        void test_invsqrt_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_invsqrt_arr(mathops::seq::fast_invsqrt_arr<float>,
                arr, size);
        }

        void test_sin_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_sin_arr(mathops::seq::fast_sin_arr<float>,
                arr, size);
        }

        void test_cos_arr(const float *arr, size_t size)
        {
            TranscedentalsTests::test_cos_arr(mathops::seq::fast_cos_arr<float>,
                arr, size);
        }
    };

    TEST_F(SeqTranscedentalsTests, FastSqrtArr1ElemArr)
    {
        test_sqrt_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArr8ElemArr)
    {
        test_sqrt_arr(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArr9ElemArr)
    {
        test_sqrt_arr(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArr16ElemArr)
    {
        test_sqrt_arr(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArr17ElemArr)
    {
        test_sqrt_arr(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArr24ElemArr)
    {
        test_sqrt_arr(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArr25ElemArr)
    {
        test_sqrt_arr(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSqrtArrBigArr)
    {
        test_sqrt_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr1ElemArr)
    {
        test_invsqrt_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr8ElemArr)
    {
        test_invsqrt_arr(_8ElemArr, _8_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr9ElemArr)
    {
        test_invsqrt_arr(_9ElemArr, _9_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr16ElemArr)
    {
        test_invsqrt_arr(_16ElemArr, _16_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr17ElemArr)
    {
        test_invsqrt_arr(_17ElemArr, _17_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr24ElemArr)
    {
        test_invsqrt_arr(_24ElemArr, _24_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArr25ElemArr)
    {
        test_invsqrt_arr(_25ElemArr, _25_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastInvSqrtArrBigArr)
    {
        test_invsqrt_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, FastSinArr1ElemArr)
    {
        test_sin_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArr8ElemArr)
    {
        test_sin_arr(_8ElemArrMinusPiPi, _8_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArr9ElemArr)
    {
        test_sin_arr(_9ElemArrMinusPiPi, _9_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArr16ElemArr)
    {
        test_sin_arr(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArr17ElemArr)
    {
        test_sin_arr(_17ElemArrMinusPiPi, _17_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArr24ElemArr)
    {
        test_sin_arr(_24ElemArrMinusPiPi, _24_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArr25ElemArr)
    {
        test_sin_arr(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastSinArrBigArr)
    {
        test_sin_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, FastCosArr1ElemArr)
    {
        test_cos_arr(_1ElemArr, _1_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArr8ElemArr)
    {
        test_cos_arr(_8ElemArrMinusPiPi, _8_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArr9ElemArr)
    {
        test_cos_arr(_9ElemArrMinusPiPi, _9_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArr16ElemArr)
    {
        test_cos_arr(_16ElemArrMinusPiPi, _16_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArr17ElemArr)
    {
        test_cos_arr(_17ElemArrMinusPiPi, _17_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArr24ElemArr)
    {
        test_cos_arr(_24ElemArrMinusPiPi, _24_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArr25ElemArr)
    {
        test_cos_arr(_25ElemArrMinusPiPi, _25_ELEM_ARR_SIZE);
    }
    TEST_F(SeqTranscedentalsTests, FastCosArrBigArr)
    {
        test_cos_arr(_bigArr, BIG_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, SqrtArrBigArr)
    {
        TranscedentalsTests::test_sqrt_arr(mathops::seq::sqrt_arr<float>,
            _9ElemArr, _9_ELEM_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, InvSqrtArrBigArr)
    {
        TranscedentalsTests::test_invsqrt_arr(mathops::seq::invsqrt_arr<float>,
            _9ElemArr, _9_ELEM_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, SinArrBigArr)
    {
        TranscedentalsTests::test_sin_arr(mathops::seq::sin_arr<float>,
            _9ElemArr, _9_ELEM_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, CosArrBigArr)
    {
        TranscedentalsTests::test_cos_arr(mathops::seq::cos_arr<float>,
            _9ElemArr, _9_ELEM_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, TanArrBigArr)
    {
        TranscedentalsTests::test_tan_arr(mathops::seq::tan_arr<float>,
            _9ElemArr, _9_ELEM_ARR_SIZE);
    }

    TEST_F(SeqTranscedentalsTests, CotArrBigArr)
    {
        TranscedentalsTests::test_cot_arr(mathops::seq::cot_arr<float>,
            _9ElemArr, _9_ELEM_ARR_SIZE);
    }
} // namespace tests
} // namespace analysis