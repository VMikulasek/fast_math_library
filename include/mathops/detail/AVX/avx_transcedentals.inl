#ifndef AVX_TRANSCEDENTALS_INL
#define AVX_TRANSCEDENTALS_INL

#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops/transcedentals.hpp>
#include <simd/simd_operations.hpp>

#define FAST_INV_SQRT_ARR(arr, res) \
    do                                                                                      \
    {                                                                                       \
        /* float xhalf = 0.5f * x; */                                                       \
        FloatOps::AvxReg x = FloatOps::load_vector(arr);                                    \
        FloatOps::AvxReg xHalf;                                                             \
        FloatOps::AvxReg halfConst = FloatOps::set_register(0.5f);                          \
        xHalf = FloatOps::mul(x, halfConst);                                                \
                                                                                            \
        /* int i = *(int *)&x; */                                                           \
        IntOps::Avx2IReg i = *reinterpret_cast<IntOps::Avx2IReg *>(&x);                     \
                                                                                            \
        /* i = 0x5f375a86 - (i >> 1); */                                                    \
        i = IntOps::shift_right(i, 1);                                                      \
        IntOps::Avx2IReg magicConstant = IntOps::set_register(0x5f375a86);                  \
        i = IntOps::sub(magicConstant, i);                                                  \
                                                                                            \
        /* x = *(float *)&i; */                                                             \
        x = *reinterpret_cast<FloatOps::AvxReg *>(&i);                                      \
                                                                                            \
        /* x = x * (1.5f - xhalf * x * x); */                                               \
        res = FloatOps::mul(x, x);                                                          \
        res = FloatOps::mul(xHalf, res);                                                    \
        FloatOps::AvxReg constReg = FloatOps::set_register(1.5f);                           \
        res = FloatOps::sub(constReg, res);                                                 \
        res = FloatOps::mul(x, res);                                                        \
    } while(0)

namespace mathops
{
namespace avx
{

#if defined(HAS_AVX) && defined(HAS_AVX2)

    using FloatOps = simd::SIMDOperations<float, simd::AVX>;
    using IntOps = simd::SIMDOperations<int, simd::AVX2>;

    inline void fast_sqrt_arr(const float *arr, size_t size, float *dst)
    {
        FloatOps::AvxReg oneReg = FloatOps::set_register(1.f);

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg res;
            FAST_INV_SQRT_ARR(arr, res);
            res = FloatOps::div(oneReg, res);
            FloatOps::materialize_register(res, dst);

            size -= AVX_FLOAT_VECTOR_SIZE;
            arr += AVX_FLOAT_VECTOR_SIZE;
            dst += AVX_FLOAT_VECTOR_SIZE;
        }

        for (size_t i = 0; i < size; size--, arr++, dst++)
        {
            *dst = fast_sqrt(*arr);
        }
    }

    inline void fast_invsqrt_arr(const float *arr, size_t size, float *dst)
    {
        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg res;
            FAST_INV_SQRT_ARR(arr, res);
            FloatOps::materialize_register(res, dst);

            size -= AVX_FLOAT_VECTOR_SIZE;
            arr += AVX_FLOAT_VECTOR_SIZE;
            dst += AVX_FLOAT_VECTOR_SIZE;
        }

        for (size_t i = 0; i < size; size--, arr++, dst++)
        {
            *dst = fast_invsqrt(*arr);
        }
    }

#endif // HAS_AVX && HAS_AVX2

} // namespace avx
} // namespace mathops

#endif // AVX_TRANSCEDENTALS_INL