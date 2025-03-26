#ifndef VEC_TRANSCENDENTALS_INL
#define VEC_TRANSCENDENTALS_INL

#include <mathops/detail/VEC/vec_transcendentals.hpp>
#include <mathops/transcendentals.hpp>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>

namespace mathops
{
namespace vec
{
    template<typename T, simd::InstructionSet FS, simd::InstructionSet IS>
    inline void _fast_invsqrt_arr8(typename simd::SIMDOperations<T, FS>::Reg &x, typename simd::SIMDOperations<T, FS>::Reg &res)
    {
        using FloatOps = simd::SIMDOperations<T, FS>;
        using IntOps = simd::SIMDOperations<int, IS>;

        /* T xhalf = 0.5f * x; */
        typename FloatOps::Reg xHalf;
        typename FloatOps::Reg halfConst = FloatOps::set_register(0.5f);
        xHalf = FloatOps::mul(x, halfConst);

        /* int i = *(int *)&x; */
        typename IntOps::Reg i = *reinterpret_cast<typename IntOps::Reg *>(&x);

        /* i = 0x5f375a86 - (i >> 1); */
        i = IntOps::shift_right(i, 1);
        typename IntOps::Reg magicConstant = IntOps::set_register(0x5f375a86);
        i = IntOps::sub(magicConstant, i);

        /* x = *(T *)&i; */
        x = *reinterpret_cast<typename FloatOps::Reg *>(&i);

        /* x = x * (1.5f - xhalf * x * x); */
        res = FloatOps::mul(x, x);
        res = FloatOps::mul(xHalf, res);
        typename FloatOps::Reg constReg = FloatOps::set_register(1.5f);
        res = FloatOps::sub(constReg, res);
        res = FloatOps::mul(x, res);
    }

    template<typename T, simd::InstructionSet FS, simd::InstructionSet IS>
    inline void fast_sqrt_arr(const T *arr, size_t size, T *dst)
    {
        using Ops = simd::SIMDOperations<T, FS>;

        typename Ops::Reg oneReg = Ops::set_register(1.f);

        while (size >= Ops::REG_SIZE)
        {
            typename Ops::Reg res;
            
            typename Ops::Reg x = Ops::load_vector(arr);
            _fast_invsqrt_arr8<T, FS, IS>(x, res);
            res = Ops::div(oneReg, res);
            
            Ops::materialize_register(res, dst);

            size -= Ops::REG_SIZE;
            arr += Ops::REG_SIZE;
            dst += Ops::REG_SIZE;
        }

        for (size_t i = 0; i < size; size--, arr++, dst++)
        {
            *dst = fast_sqrt(*arr);
        }
    }

    template<typename T, simd::InstructionSet FS, simd::InstructionSet IS>
    inline void fast_invsqrt_arr(const T *arr, size_t size, T *dst)
    {
        using Ops = simd::SIMDOperations<T, FS>;

        while (size >= Ops::REG_SIZE)
        {
            typename Ops::Reg res;

            typename Ops::Reg x = Ops::load_vector(arr);
            _fast_invsqrt_arr8<T, FS, IS>(x, res);
            
            Ops::materialize_register(res, dst);

            size -= Ops::REG_SIZE;
            arr += Ops::REG_SIZE;
            dst += Ops::REG_SIZE;
        }

        for (size_t i = 0; i < size; size--, arr++, dst++)
        {
            *dst = fast_invsqrt(*arr);
        }
    }

    template<typename T, simd::InstructionSet S>
    inline typename simd::SIMDOperations<T, S>::Reg _sin5q8(
        const typename simd::SIMDOperations<T, S>::Reg &x,
        const typename simd::SIMDOperations<T, S>::Reg &A,
        const typename simd::SIMDOperations<T, S>::Reg &B,
        const typename simd::SIMDOperations<T, S>::Reg &C)
    {
        using Ops = simd::SIMDOperations<T, S>;

        // x2 = x * x;
        typename Ops::Reg x2 = Ops::mul(x, x);

        // return x * (A + x2 * (B + x2 * C));
        typename Ops::Reg res = Ops::mul(x2, C);
        res = Ops::add(B, res);
        res = Ops::mul(x2, res);
        res = Ops::add(A, res);
        res = Ops::mul(x, res);
        return res;
    }

    template<typename T, simd::InstructionSet S>
    inline void _init_sincos_constants(
        typename simd::SIMDOperations<T, S>::Reg &AVec,
        typename simd::SIMDOperations<T, S>::Reg &BVec,
        typename simd::SIMDOperations<T, S>::Reg &CVec,
        typename simd::SIMDOperations<T, S>::Reg &pi2Vec,
        typename simd::SIMDOperations<T, S>::Reg &quarter)
    {
        using Ops = simd::SIMDOperations<T, S>;

        AVec = Ops::set_register(A);
        BVec = Ops::set_register(B);
        CVec = Ops::set_register(C);
        pi2Vec = Ops::set_register(pi2);
        quarter = Ops::set_register(0.25);
    }

    template<typename T, simd::InstructionSet S>
    inline typename simd::SIMDOperations<T, S>::Reg _compute_sincos_z(
        const typename simd::SIMDOperations<T, S>::Reg &x_2,
        const typename simd::SIMDOperations<T, S>::Reg &quarter)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg z = Ops::round(x_2);
        z = Ops::sub(x_2, z);
        z = Ops::abs(z);
        z = Ops::sub(quarter, z);

        return z;
    }

    template<typename T, simd::InstructionSet S>
    inline typename simd::SIMDOperations<T, S>::Reg _fast_sin_arr8(const typename simd::SIMDOperations<T, S>::Reg &num,
        const typename simd::SIMDOperations<T, S>::Reg &pi2Vec, const typename simd::SIMDOperations<T, S>::Reg &quarter,
        const typename simd::SIMDOperations<T, S>::Reg &AVec, const typename simd::SIMDOperations<T, S>::Reg &BVec,
        const typename simd::SIMDOperations<T, S>::Reg &CVec)
    {
        using Ops = simd::SIMDOperations<T, S>;

        // T x_2 = 0.25f - num * pi2;
        typename Ops::Reg x_2 = Ops::mul(num, pi2Vec);
        x_2 = Ops::sub(quarter, x_2);

        // T z = 0.25f - abs(x_2 - round(x_2));
        typename Ops::Reg z = _compute_sincos_z<T, S>(x_2, quarter);

        // dst = sin5q(z);
        return _sin5q8<T, S>(z, AVec, BVec, CVec);
    }

    template<typename T, simd::InstructionSet S>
    inline void fast_sin_arr(const T *src, size_t size, T *dst)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        _init_sincos_constants<T, S>(AVec, BVec, CVec, pi2Vec, quarter);
        
        while (size >= Ops::REG_SIZE)
        {
            typename Ops::Reg num = Ops::load_vector(src);
            typename Ops::Reg res = _fast_sin_arr8<T, S>(num, pi2Vec,
                quarter, AVec, BVec, CVec);

            Ops::materialize_register(res, dst);

            size -= Ops::REG_SIZE;
            src += Ops::REG_SIZE;
            dst += Ops::REG_SIZE;
        }

        for (unsigned i = 0; i < size; i++)
        {
            dst[i] = fast_sin(src[i]);
        }
    }

    template<typename T, simd::InstructionSet S>
    inline typename simd::SIMDOperations<T, S>::Reg _fast_cos_arr8(const typename simd::SIMDOperations<T, S>::Reg &num,
        const typename simd::SIMDOperations<T, S>::Reg &pi2Vec, const typename simd::SIMDOperations<T, S>::Reg &quarter,
        const typename simd::SIMDOperations<T, S>::Reg &AVec, const typename simd::SIMDOperations<T, S>::Reg &BVec,
        const typename simd::SIMDOperations<T, S>::Reg &CVec)
    {
        using Ops = simd::SIMDOperations<T, S>;

        // T x_2 = num * pi2;
        typename Ops::Reg x_2 = Ops::mul(num, pi2Vec);

        // T z = 0.25f - abs(x_2 - round(x_2));            
        typename Ops::Reg z = _compute_sincos_z<T, S>(x_2, quarter);

        // dst = sin5q(z);
        return _sin5q8<T, S>(z, AVec, BVec, CVec);
    }

    template<typename T, simd::InstructionSet S>
    inline void fast_cos_arr(const T *src, size_t size, T *dst)
    {
        using Ops = simd::SIMDOperations<T, S>;

        typename Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        _init_sincos_constants<T, S>(AVec, BVec, CVec, pi2Vec, quarter);

        while (size >= Ops::REG_SIZE)
        {
            typename Ops::Reg num = Ops::load_vector(src);
            typename Ops::Reg res = _fast_cos_arr8<T, S>(num, pi2Vec,
                quarter, AVec, BVec, CVec);
            Ops::materialize_register(res, dst);

            size -= Ops::REG_SIZE;
            src += Ops::REG_SIZE;
            dst += Ops::REG_SIZE;
        }

        for (unsigned i = 0; i < size; i++)
        {
            dst[i] = fast_cos(src[i]);
        }
    }
} // namespace vec
} // namespace mathops

#endif // VEC_TRANSCENDENTALS_INL