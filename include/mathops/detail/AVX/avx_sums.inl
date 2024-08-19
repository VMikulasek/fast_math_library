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
    inline FloatOps::AvxReg load_reg(const float *&arr, size_t &size)
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

        FloatOps::AvxReg tmpResultReg = load_reg(arr, size);

        FloatOps::AvxReg secondOpReg;

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            secondOpReg = load_reg(arr, size);
            tmpResultReg = FloatOps::add(tmpResultReg, secondOpReg);
        }

        auto resultArr1 = FloatOps::materialize_register(tmpResultReg);

        float tailSum = seq::sum(arr, size);

        // merge all sums to the 0th and 4th indexes
        alignas(32) const float zeroVec[8]{ 0, 0, 0, 0, 0, 0, 0, 0 };
        secondOpReg = FloatOps::load_vector(zeroVec);
        tmpResultReg = FloatOps::horizontal_add(tmpResultReg, secondOpReg);
        tmpResultReg = FloatOps::horizontal_add(tmpResultReg, secondOpReg);

        // materialize and return final sum
        auto resultArr = FloatOps::materialize_register(tmpResultReg);

        return resultArr[0] + resultArr[4] + tailSum;
    }

#endif

} // namespace avx
} // namespace math

#endif // AVX_SUMS_INL