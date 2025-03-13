#ifndef SIMD_VEC2_AVX_FLOAT_INL
#define SIMD_VEC2_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec2_avx_float.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>

namespace simd
{
namespace avx
{
    inline Vec2f addv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::add(reg1, reg2);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec2f subv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::sub(reg1, reg2);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec2f mulv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec2f divv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::div(reg1, reg2);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec2f absv2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::load_vector(vec.data);

        Ops::AvxReg resReg = Ops::abs(reg);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec2f minv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::min(reg1, reg2);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec2f maxv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::max(reg1, reg2);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec2f fast_sqrtv2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::load_vector(vec.data);

        Ops::AvxReg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);
        Ops::AvxReg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec2f fast_invsqrtv2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::load_vector(vec.data);

        Ops::AvxReg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec2f fast_sinv2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::load_vector(vec.data);
        
        Ops::AvxReg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::AvxReg resReg = mathops::avx::_fast_sin_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec2f fast_cosv2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::load_vector(vec.data);
        
        Ops::AvxReg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::AvxReg resReg = mathops::avx::_fast_cos_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec2f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline float dotv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::load_vector(vec1.data);
        Ops::AvxReg reg2 = Ops::load_vector(vec2.data);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
    inline float lengthv2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::load_vector(vec.data);

        reg = Ops::mul(reg, reg);
        reg = Ops::horizontal_add(reg, reg);
        reg = Ops::horizontal_add(reg, reg);

        return mathops::sqrt(Ops::materialize_register_at_index(reg, 0));
    }
    inline Vec2f normalizev2f(const Vec2f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        auto lengthReg = Ops::set_register(lengthv2f(vec));
        auto inputReg = Ops::load_vector(vec.data);
        auto result = Ops::div(inputReg, lengthReg);

        Vec2f res;
        Ops::materialize_register(result, res.data);
        return res;
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC2_AVX_FLOAT_INL