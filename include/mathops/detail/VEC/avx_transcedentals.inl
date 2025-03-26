#ifndef AVX_TRANSCEDENTALS_INL
#define AVX_TRANSCEDENTALS_INL

#include <mathops/detail/VEC/avx_transcedentals.hpp>
#include <mathops/transcedentals.hpp>
#include <simd/simd_operations.hpp>

namespace mathops
{
namespace avx
{

#if defined(HAS_AVX) && defined(HAS_AVX2)

    using FloatOps = simd::SIMDOperations<float, simd::AVX>;
    using IntOps = simd::SIMDOperations<int, simd::AVX2>;

    inline void _fast_invsqrt_arr8(FloatOps::Reg &x, FloatOps::Reg &res)
    {
        /* float xhalf = 0.5f * x; */
        FloatOps::Reg xHalf;
        FloatOps::Reg halfConst = FloatOps::set_register(0.5f);
        xHalf = FloatOps::mul(x, halfConst);

        /* int i = *(int *)&x; */
        IntOps::Reg i = *reinterpret_cast<IntOps::Reg *>(&x);

        /* i = 0x5f375a86 - (i >> 1); */
        i = IntOps::shift_right(i, 1);
        IntOps::Reg magicConstant = IntOps::set_register(0x5f375a86);
        i = IntOps::sub(magicConstant, i);

        /* x = *(float *)&i; */
        x = *reinterpret_cast<FloatOps::Reg *>(&i);

        /* x = x * (1.5f - xhalf * x * x); */
        res = FloatOps::mul(x, x);
        res = FloatOps::mul(xHalf, res);
        FloatOps::Reg constReg = FloatOps::set_register(1.5f);
        res = FloatOps::sub(constReg, res);
        res = FloatOps::mul(x, res);
    }

    inline void fast_sqrt_arr(const float *arr, size_t size, float *dst)
    {
        FloatOps::Reg oneReg = FloatOps::set_register(1.f);

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::Reg res;
            
            FloatOps::Reg x = FloatOps::load_vector(arr);
            _fast_invsqrt_arr8(x, res);
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
            FloatOps::Reg res;

            FloatOps::Reg x = FloatOps::load_vector(arr);
            _fast_invsqrt_arr8(x, res);
            
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

    inline FloatOps::Reg _sin5q8(
        const FloatOps::Reg &x,
        const FloatOps::Reg &A,
        const FloatOps::Reg &B,
        const FloatOps::Reg &C)
    {
        // x2 = x * x;
        FloatOps::Reg x2 = FloatOps::mul(x, x);

        // return x * (A + x2 * (B + x2 * C));
        FloatOps::Reg res = FloatOps::mul(x2, C);
        res = FloatOps::add(B, res);
        res = FloatOps::mul(x2, res);
        res = FloatOps::add(A, res);
        res = FloatOps::mul(x, res);
        return res;
    }

    inline void _init_sincos_constants(
        FloatOps::Reg &AVec,
        FloatOps::Reg &BVec,
        FloatOps::Reg &CVec,
        FloatOps::Reg &pi2Vec,
        FloatOps::Reg &quarter)
    {
        AVec = FloatOps::set_register(A);
        BVec = FloatOps::set_register(B);
        CVec = FloatOps::set_register(C);
        pi2Vec = FloatOps::set_register(pi2);
        quarter = FloatOps::set_register(0.25);
    }

    inline FloatOps::Reg _compute_sincos_z(
        const FloatOps::Reg &x_2,
        const FloatOps::Reg &quarter)
    {
        FloatOps::Reg z = FloatOps::round(x_2);
        z = FloatOps::sub(x_2, z);
        z = FloatOps::abs(z);
        z = FloatOps::sub(quarter, z);

        return z;
    }

    inline FloatOps::Reg _fast_sin_arr8(const FloatOps::Reg &num,
        const FloatOps::Reg &pi2Vec, const FloatOps::Reg &quarter,
        const FloatOps::Reg &AVec, const FloatOps::Reg &BVec,
        const FloatOps::Reg &CVec)
    {
        // float x_2 = 0.25f - num * pi2;
        FloatOps::Reg x_2 = FloatOps::mul(num, pi2Vec);
        x_2 = FloatOps::sub(quarter, x_2);

        // float z = 0.25f - abs(x_2 - round(x_2));
        FloatOps::Reg z = _compute_sincos_z(x_2, quarter);

        // dst = sin5q(z);
        return _sin5q8(z, AVec, BVec, CVec);
    }

    inline void fast_sin_arr(const float *src, size_t size, float *dst)
    {
        FloatOps::Reg AVec, BVec, CVec, pi2Vec, quarter;
        _init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        
        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::Reg num = FloatOps::load_vector(src);
            FloatOps::Reg res = _fast_sin_arr8(num, pi2Vec,
                quarter, AVec, BVec, CVec);

            FloatOps::materialize_register(res, dst);

            size -= AVX_FLOAT_VECTOR_SIZE;
            src += AVX_FLOAT_VECTOR_SIZE;
            dst += AVX_FLOAT_VECTOR_SIZE;
        }

        for (unsigned i = 0; i < size; i++)
        {
            dst[i] = fast_sin(src[i]);
        }
    }

    inline FloatOps::Reg _fast_cos_arr8(const FloatOps::Reg &num,
        const FloatOps::Reg &pi2Vec, const FloatOps::Reg &quarter,
        const FloatOps::Reg &AVec, const FloatOps::Reg &BVec,
        const FloatOps::Reg &CVec)
    {
        // float x_2 = num * pi2;
        FloatOps::Reg x_2 = FloatOps::mul(num, pi2Vec);

        // float z = 0.25f - abs(x_2 - round(x_2));            
        FloatOps::Reg z = _compute_sincos_z(x_2, quarter);

        // dst = sin5q(z);
        return _sin5q8(z, AVec, BVec, CVec);
    }

    inline void fast_cos_arr(const float *src, size_t size, float *dst)
    {
        FloatOps::Reg AVec, BVec, CVec, pi2Vec, quarter;
        _init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);

        while (size >= AVX_FLOAT_VECTOR_SIZE)
        {
            FloatOps::Reg num = FloatOps::load_vector(src);
            FloatOps::Reg res = _fast_cos_arr8(num, pi2Vec,
                quarter, AVec, BVec, CVec);
            FloatOps::materialize_register(res, dst);

            size -= AVX_FLOAT_VECTOR_SIZE;
            src += AVX_FLOAT_VECTOR_SIZE;
            dst += AVX_FLOAT_VECTOR_SIZE;
        }

        for (unsigned i = 0; i < size; i++)
        {
            dst[i] = fast_cos(src[i]);
        }
    }

#endif // HAS_AVX && HAS_AVX2

} // namespace avx
} // namespace mathops

#endif // AVX_TRANSCEDENTALS_INL