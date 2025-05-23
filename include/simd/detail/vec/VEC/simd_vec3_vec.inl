#ifndef SIMD_VEC3_VEC_INL
#define SIMD_VEC3_VEC_INL

#include <simd/detail/vec/VEC/simd_vec3_vec.hpp>
#include <mathops/detail/VEC/vec_transcendentals.hpp>
#include <simd/simd_common.hpp>

namespace simd
{
namespace vec
{
    template<typename T, InstructionSet S>
    inline Vec<3, T> addv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::add(reg1, reg2);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<3, T> subv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::sub(reg1, reg2);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<3, T> mulv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::mul(reg1, reg2);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<3, T> divv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::div(reg1, reg2);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<3, T> absv3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        typename Ops::Reg resReg = Ops::abs(reg);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet S>
    inline Vec<3, T> minv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::min(reg1, reg2);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet S>
    inline Vec<3, T> maxv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::max(reg1, reg2);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<3, T> fast_sqrtv3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, FS>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        typename Ops::Reg resReg;
        mathops::vec::_fast_invsqrt_arr8<T, FS, IS>(reg, resReg);
        typename Ops::Reg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<3, T> fast_invsqrtv3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, FS>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        typename Ops::Reg resReg;
        mathops::vec::_fast_invsqrt_arr8<T, FS, IS>(reg, resReg);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_sinv3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);
        
        typename Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::vec::_init_sincos_constants<T, S>(AVec, BVec, CVec, pi2Vec, quarter);
        typename Ops::Reg resReg = mathops::vec::_fast_sin_arr8<T, S>(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet S>
    inline Vec<3, T> fast_cosv3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);
        
        typename Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::vec::_init_sincos_constants<T, S>(AVec, BVec, CVec, pi2Vec, quarter);
        typename Ops::Reg resReg = mathops::vec::_fast_cos_arr8<T, S>(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec<3, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<3, T> crossv3v(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg vec1Mul1 = Ops::load_vector(vec1.data);
        typename Ops::Reg vec2Mul1 = Ops::set_register_each(vec2.y, vec2.z, vec2.x, 0, 0, 0, 0, 0);
        typename Ops::Reg vec1Mul2 = Ops::set_register_each(vec1.y, vec1.z, vec1.x, 0, 0, 0, 0, 0);
        typename Ops::Reg vec2Mul2 = Ops::load_vector(vec2.data);

        typename Ops::Reg firstProduct = Ops::mul(vec1Mul1, vec2Mul1);
        typename Ops::Reg secondProduct = Ops::mul(vec1Mul2, vec2Mul2);

        typename Ops::Reg resReg = Ops::sub(firstProduct, secondProduct);

        return Vec<3, T>(
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 0)
        );
    }
    template<typename T, InstructionSet S>
    inline T dotv3(const Vec<3, T> &vec1, const Vec<3, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
    template<typename T, InstructionSet S>
    inline T lengthv3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        reg = Ops::mul(reg, reg);
        reg = Ops::horizontal_add(reg, reg);
        reg = Ops::horizontal_add(reg, reg);

        return mathops::sqrt(Ops::materialize_register_at_index(reg, 0));
    }
    template<typename T, InstructionSet S>
    inline Vec<3, T> normalizev3(const Vec<3, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg inputReg = Ops::load_vector(vec.data);

        typename Ops::Reg lengthReg = Ops::mul(inputReg, inputReg);
        lengthReg = Ops::horizontal_add(lengthReg, lengthReg);
        lengthReg = Ops::horizontal_add(lengthReg, lengthReg);
        lengthReg = Ops::set_register(mathops::sqrt(Ops::materialize_register_at_index(lengthReg, 0)));

        typename Ops::Reg result = Ops::div(inputReg, lengthReg);

        Vec<3, T> res;
        Ops::materialize_register(result, res.data);
        return res;
    }
} // namespace vec
} // namespace simd

#endif // SIMD_VEC3_VEC_INL