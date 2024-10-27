#ifndef AVX_TRANSCEDENTALS_INL
#define AVX_TRANSCEDENTALS_INL

#include <mathops/detail/AVX/avx_transcedentals.hpp>
#include <mathops/transcedentals.hpp>
#include <simd/simd_operations.hpp>

namespace mathops
{
namespace avx
{

#if defined(HAS_AVX) && defined(HAS_AVX2)

    using FloatOps = simd::SIMDOperations<float, simd::AVX>;
    using IntOps = simd::SIMDOperations<int, simd::AVX2>;

    inline void _fast_invsqrt_arr8(const float *arr, FloatOps::AvxReg &res)
    {
        /* float xhalf = 0.5f * x; */
        FloatOps::AvxReg x = FloatOps::load_vector(arr);
        FloatOps::AvxReg xHalf;
        FloatOps::AvxReg halfConst = FloatOps::set_register(0.5f);
        xHalf = FloatOps::mul(x, halfConst);

        /* int i = *(int *)&x; */
        IntOps::Avx2IReg i = *reinterpret_cast<IntOps::Avx2IReg *>(&x);

        /* i = 0x5f375a86 - (i >> 1); */
        i = IntOps::shift_right(i, 1);
        IntOps::Avx2IReg magicConstant = IntOps::set_register(0x5f375a86);
        i = IntOps::sub(magicConstant, i);

        /* x = *(float *)&i; */
        x = *reinterpret_cast<FloatOps::AvxReg *>(&i);

        /* x = x * (1.5f - xhalf * x * x); */
        res = FloatOps::mul(x, x);
        res = FloatOps::mul(xHalf, res);
        FloatOps::AvxReg constReg = FloatOps::set_register(1.5f);
        res = FloatOps::sub(constReg, res);
        res = FloatOps::mul(x, res);
    }

    inline void fast_sqrt_arr(const float *arr, size_t size, float *dst)
    {
        FloatOps::AvxReg oneReg = FloatOps::set_register(1.f);

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg res;
            _fast_invsqrt_arr8(arr, res);
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
            _fast_invsqrt_arr8(arr, res);
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

    inline FloatOps::AvxReg _sin5q8(
        const FloatOps::AvxReg &x,
        const FloatOps::AvxReg &A,
        const FloatOps::AvxReg &B,
        const FloatOps::AvxReg &C)
    {
        // x2 = x * x;
        FloatOps::AvxReg x2 = FloatOps::mul(x, x);

        // return x * (A + x2 * (B + x2 * C));
        FloatOps::AvxReg res = FloatOps::mul(x2, C);
        res = FloatOps::add(B, res);
        res = FloatOps::mul(x2, res);
        res = FloatOps::add(A, res);
        res = FloatOps::mul(x, res);
        return res;
    }

    inline void _init_sincos_constants(
        FloatOps::AvxReg &AVec,
        FloatOps::AvxReg &BVec,
        FloatOps::AvxReg &CVec,
        FloatOps::AvxReg &pi2Vec,
        FloatOps::AvxReg &quarter)
    {
        AVec = FloatOps::set_register(A);
        BVec = FloatOps::set_register(B);
        CVec = FloatOps::set_register(C);
        pi2Vec = FloatOps::set_register(pi2);
        quarter = FloatOps::set_register(0.25);
    }

    inline FloatOps::AvxReg _compute_sincos_z(
        const FloatOps::AvxReg &x_2,
        const FloatOps::AvxReg &quarter)
    {
        FloatOps::AvxReg z = FloatOps::round(x_2);
        z = FloatOps::sub(x_2, z);
        z = FloatOps::abs(z);
        z = FloatOps::sub(quarter, z);

        return z;
    }

    inline void fast_sin_arr(const float *src, size_t size, float *dst)
    {
        FloatOps::AvxReg AVec, BVec, CVec, pi2Vec, quarter;
        _init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg num = FloatOps::load_vector(src);

            // float x_2 = 0.25f - num * pi2;
            FloatOps::AvxReg x_2 = FloatOps::mul(num, pi2Vec);
            x_2 = FloatOps::sub(quarter, pi2Vec);

            // float z = 0.25f - abs(x_2 - round(x_2));            
            FloatOps::AvxReg z = _compute_sincos_z(x_2, quarter);

            // dst = sin5q(z);
            FloatOps::AvxReg res = _sin5q8(z, AVec, BVec, CVec);
            FloatOps::materialize_register(res, dst);

            size -= AVX_FLOAT_VECTOR_SIZE;
            src += AVX_FLOAT_VECTOR_SIZE;
            dst += AVX_FLOAT_VECTOR_SIZE;
        }
    }

    inline void fast_cos_arr(const float *src, size_t size, float *dst)
    {
        FloatOps::AvxReg AVec, BVec, CVec, pi2Vec, quarter;
        _init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::AvxReg num = FloatOps::load_vector(src);

            // float x_2 = num * pi2;
            FloatOps::AvxReg x_2 = FloatOps::mul(num, pi2Vec);

            // float z = 0.25f - abs(x_2 - round(x_2));            
            FloatOps::AvxReg z = _compute_sincos_z(x_2, quarter);

            // dst = sin5q(z);
            FloatOps::AvxReg res = _sin5q8(z, AVec, BVec, CVec);
            FloatOps::materialize_register(res, dst);

            size -= AVX_FLOAT_VECTOR_SIZE;
            src += AVX_FLOAT_VECTOR_SIZE;
            dst += AVX_FLOAT_VECTOR_SIZE;
        }
    }

#endif // HAS_AVX && HAS_AVX2

} // namespace avx
} // namespace mathops

#endif // AVX_TRANSCEDENTALS_INL