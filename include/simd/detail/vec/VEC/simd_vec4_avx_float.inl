#ifndef SIMD_VEC4_AVX_FLOAT_INL
#define SIMD_VEC4_AVX_FLOAT_INL

#include <simd/detail/vec/VEC/simd_vec4_avx_float.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>

namespace simd
{
namespace avx
{
    inline Vec4f addv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::add(reg1, reg2);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec4f subv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::sub(reg1, reg2);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec4f mulv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::mul(reg1, reg2);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec4f divv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::div(reg1, reg2);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec4f absv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        Ops::Reg resReg = Ops::abs(reg);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec4f minv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::min(reg1, reg2);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec4f maxv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::max(reg1, reg2);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec4f fast_sqrtv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        Ops::Reg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);
        Ops::Reg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec4f fast_invsqrtv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        Ops::Reg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec4f fast_sinv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);
        
        Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::Reg resReg = mathops::avx::_fast_sin_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec4f fast_cosv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);
        
        Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::Reg resReg = mathops::avx::_fast_cos_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec4f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline float dotv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
    inline float lengthv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        reg = Ops::mul(reg, reg);
        reg = Ops::horizontal_add(reg, reg);
        reg = Ops::horizontal_add(reg, reg);

        return mathops::sqrt(Ops::materialize_register_at_index(reg, 0));
    }
    inline Vec4f normalizev4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        auto lengthReg = Ops::set_register(lengthv4f(vec));
        auto inputReg = Ops::load_vector(vec.data);
        auto result = Ops::div(inputReg, lengthReg);

        Vec4f res;
        Ops::materialize_register(result, res.data);
        return res;
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC4_AVX_FLOAT_INL