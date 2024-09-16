#ifndef AVX_TRANSCEDENTALS_INL
#define AVX_TRANSCEDENTALS_INL

#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <simd/simd_operations.hpp>

namespace mathops
{
namespace avx
{

#ifdef HAS_AVX

    using FloatOps = simd::SIMDOperations<float, simd::AVX>;

    inline FloatOps::AvxReg _fast_invsqrt_arr8(const float *arr)
    {
        FloatOps::AvxReg x = FloatOps::load_vector(arr);
        FloatOps::AvxReg halfConst = FloatOps::set_register(0.5f);
        FloatOps::AvxReg xHalf = FloatOps::mul(x, halfConst);
    }

    inline void fast_sqrt_arr(float *arr, size_t size)
    {
        //TODO
    }

#endif // HAS_AVX

} // namespace avx
} // namespace mathops

#endif // AVX_TRANSCEDENTALS_INL