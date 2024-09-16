#ifndef AVX_SUMS_INL
#define AVX_SUMS_INL

#include <mathops/detail/AVX/avx_sums.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>
#include <simd/simd_operations.hpp>

namespace mathops
{
namespace avx
{

#ifdef HAS_AVX

    using FloatOps = simd::SIMDOperations<float, simd::AVX>;

    // private
    inline FloatOps::AvxReg _load_reg(const float *&arr, size_t &size)
    {
        auto reg = FloatOps::load_vector(arr);
        arr += AVX_FLOAT_VECTOR_SIZE;
        size -= AVX_FLOAT_VECTOR_SIZE;
        return reg; 
    }

    inline float sum(const float *arr, size_t size)
    {        
        if (size < AVX_FLOAT_VECTOR_SIZE)
        {
            return seq::sum(arr, size);
        }

        FloatOps::AvxReg tmpResultReg = _load_reg(arr, size);

        FloatOps::AvxReg secondOpReg;

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            secondOpReg = _load_reg(arr, size);
            tmpResultReg = FloatOps::add(tmpResultReg, secondOpReg);
        }

        float tailSum = seq::sum(arr, size);

        // merge all sums to the 0th and 4th indexes
        secondOpReg = FloatOps::load_zero_vector();
        tmpResultReg = FloatOps::horizontal_add(tmpResultReg, secondOpReg);
        tmpResultReg = FloatOps::horizontal_add(tmpResultReg, secondOpReg);

        // materialize and return final sum
        alignas(AVX_ALIGNMENT) float resultArr[AVX_FLOAT_VECTOR_SIZE];
        FloatOps::materialize_register(tmpResultReg, resultArr);

        return resultArr[0] + resultArr[4] + tailSum;
    }

    inline void prefix_sum(const float *arr, size_t size, float *dstArr)
    {
        FloatOps::AvxReg zeroVec = FloatOps::load_zero_vector();

        FloatOps::AvxReg lastElemOfCalculatedSequenceDistributed = FloatOps::load_zero_vector();

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg res = _load_reg(arr, size);

            // calculate prefix sum for halves isolated
            FloatOps::AvxReg shifted = FloatOps::rotate_halves_right_32bits(res);
            shifted = FloatOps::blend<0b11101110>(zeroVec, shifted);
            res = FloatOps::add(res, shifted);
            shifted = FloatOps::rotate_halves_64bits(res);
            shifted = FloatOps::blend<0b11001100>(zeroVec, shifted);
            res = FloatOps::add(res, shifted);

            // calculate prefix sum for whole register isolated
            FloatOps::AvxReg lastElemOfFirstHalf = FloatOps::permute_reg_inside_halves<0b11111111>(res);
            lastElemOfFirstHalf = FloatOps::blend<0b00001111>(zeroVec, lastElemOfFirstHalf);
            lastElemOfFirstHalf = FloatOps::swap_halves(lastElemOfFirstHalf);
            res = FloatOps::add(res, lastElemOfFirstHalf);

            // calculate prefix sum for whole register
            res = FloatOps::add(res, lastElemOfCalculatedSequenceDistributed);

            // update last elem distribution register
            lastElemOfCalculatedSequenceDistributed = FloatOps::permute_reg_inside_halves<0b11111111>(res);
            lastElemOfCalculatedSequenceDistributed = FloatOps::distribute_high_half(lastElemOfCalculatedSequenceDistributed);

            FloatOps::materialize_register(res, dstArr);
            dstArr += AVX_FLOAT_VECTOR_SIZE;
        }

        alignas(AVX_ALIGNMENT) float tmp[8];
        FloatOps::materialize_register(lastElemOfCalculatedSequenceDistributed, tmp);

        float lastElemOfCalculatedSequence = tmp[0];
        for (; size > 0; size--, arr++, dstArr++)
        {
            lastElemOfCalculatedSequence = *dstArr = *arr + lastElemOfCalculatedSequence;
        }
    }

#endif

} // namespace avx
} // namespace math

#endif // AVX_SUMS_INL