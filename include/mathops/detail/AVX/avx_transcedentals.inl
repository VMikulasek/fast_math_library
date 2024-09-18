#ifndef AVX_TRANSCEDENTALS_INL
#define AVX_TRANSCEDENTALS_INL

#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <simd/simd_operations.hpp>

namespace mathops
{
namespace avx
{

#if defined(HAS_AVX) && defined(HAS_AVX2)

    using FloatOps = simd::SIMDOperations<float, simd::AVX>;
    using IntOps = simd::SIMDOperations<int, simd::AVX2>;

    inline FloatOps::AvxReg _fast_invsqrt_arr8(const float *arr)
    {
        // float xhalf = 0.5f * x;
        FloatOps::AvxReg x = FloatOps::load_vector(arr);
        FloatOps::AvxReg xHalf;
        {
            FloatOps::AvxReg halfConst = FloatOps::set_register(0.5f);
            xHalf = FloatOps::mul(x, halfConst);
        }

        // int i = *(int *)&x;
        IntOps::Avx2IReg i = IntOps::convert_from_float(x);

        // i = 0x5f375a86 - (i >> 1);
        i = IntOps::shift_right(i, 1);
        IntOps::Avx2IReg magicConstant = IntOps::set_register(0x5f375a86);
        i = IntOps::sub(magicConstant, i);

        // x = *(float *)&i;
        x = FloatOps::convert_from_int(i);

        // x = x * (1.5f - xhalf * x * x);
        FloatOps::AvxReg res = FloatOps::mul(x, x);
        res = FloatOps::mul(xHalf, res);
        {
            FloatOps::AvxReg constReg = FloatOps::set_register(1.5f);
            res = FloatOps::sub(constReg, res);
        }
        res = FloatOps::mul(x, res);

        // return x
        return res;
    }

    inline void fast_sqrt_arr(const float *arr, size_t size, float *dst)
    {
        //TODO
    }

    inline void fast_invsqrt_arr(const float *arr, size_t size, float *dst)
    {
        //TODO
    }

#endif // HAS_AVX && HAS_AVX2

} // namespace avx
} // namespace mathops

#endif // AVX_TRANSCEDENTALS_INL