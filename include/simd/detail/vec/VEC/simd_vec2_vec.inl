#ifndef SIMD_VEC2_VEC_INL
#define SIMD_VEC2_VEC_INL

#include <simd/detail/vec/VEC/simd_vec2_vec.hpp>
#include <mathops/detail/VEC/vec_transcendentals.hpp>

namespace simd
{
namespace vec
{
    template<typename T, InstructionSet S>
    inline Vec<2, T> addv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::add(reg1, reg2);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<2, T> subv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::sub(reg1, reg2);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<2, T> mulv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::mul(reg1, reg2);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<2, T> divv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::div(reg1, reg2);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<2, T> absv2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        typename Ops::Reg resReg = Ops::abs(reg);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet S>
    inline Vec<2, T> minv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::min(reg1, reg2);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet S>
    inline Vec<2, T> maxv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::max(reg1, reg2);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<2, T> fast_sqrtv2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, FS>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        typename Ops::Reg resReg;
        mathops::vec::_fast_invsqrt_arr8<T, FS, IS>(reg, resReg);
        typename Ops::Reg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet FS, InstructionSet IS>
    inline Vec<2, T> fast_invsqrtv2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, FS>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        typename Ops::Reg resReg;
        mathops::vec::_fast_invsqrt_arr8<T, FS, IS>(reg, resReg);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_sinv2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);
        
        typename Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::vec::_init_sincos_constants<T, S>(AVec, BVec, CVec, pi2Vec, quarter);
        typename Ops::Reg resReg = mathops::vec::_fast_sin_arr8<T, S>(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    template<typename T, InstructionSet S>
    inline Vec<2, T> fast_cosv2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);
        
        typename Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::vec::_init_sincos_constants<T, S>(AVec, BVec, CVec, pi2Vec, quarter);
        typename Ops::Reg resReg = mathops::vec::_fast_cos_arr8<T, S>(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec<2, T> res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    template<typename T, InstructionSet S>
    inline T dotv2(const Vec<2, T> &vec1, const Vec<2, T> &vec2)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg1 = Ops::load_vector(vec1.data);
        typename Ops::Reg reg2 = Ops::load_vector(vec2.data);

        typename Ops::Reg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
    template<typename T, InstructionSet S>
    inline T lengthv2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg reg = Ops::load_vector(vec.data);

        reg = Ops::mul(reg, reg);
        reg = Ops::horizontal_add(reg, reg);

        return mathops::sqrt(Ops::materialize_register_at_index(reg, 0));
    }
    template<typename T, InstructionSet S>
    inline Vec<2, T> normalizev2(const Vec<2, T> &vec)
    {
        using Ops = SIMDOperations<T, S>;

        typename Ops::Reg inputReg = Ops::load_vector(vec.data);

        typename Ops::Reg lengthReg = Ops::mul(inputReg, inputReg);
        lengthReg = Ops::horizontal_add(lengthReg, lengthReg);
        lengthReg = Ops::set_register(mathops::sqrt(Ops::materialize_register_at_index(lengthReg, 0)));

        auto result = Ops::div(inputReg, lengthReg);

        Vec<2, T> res;
        Ops::materialize_register(result, res.data);
        return res;
    }
} // namespace vec
} // namespace simd

#endif // SIMD_VEC2_VEC_INL