#ifndef SIMD_VEC4_AVX_FLOAT_INL
#define SIMD_VEC4_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec4_avx_float.hpp>
#include <mathops/detail/AVX/avx_transcedentals.hpp>

namespace simd
{
namespace avx
{
    inline Vec4f addv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::add(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline Vec4f subv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::sub(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline Vec4f mulv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline Vec4f divv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::div(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline Vec4f absv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::abs(reg);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }
    inline Vec4f minv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::min(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }
    inline Vec4f maxv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::max(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline Vec4f fast_sqrtv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);

        Ops::AvxReg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);
        Ops::AvxReg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }
    inline Vec4f fast_invsqrtv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);

        Ops::AvxReg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline Vec4f fast_sinv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);
        
        Ops::AvxReg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::AvxReg resReg = mathops::avx::_fast_sin_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }
    inline Vec4f fast_cosv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);
        
        Ops::AvxReg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::AvxReg resReg = mathops::avx::_fast_cos_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 3)
        );
    }

    inline float dotv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, vec1.w, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, vec2.w, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
    inline float lengthv4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);

        reg = Ops::mul(reg, reg);
        reg = Ops::horizontal_add(reg, reg);
        reg = Ops::horizontal_add(reg, reg);

        return mathops::sqrt(Ops::materialize_register_at_index(reg, 0));
    }
    inline Vec4f normalizev4f(const Vec4f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        auto lengthReg = Ops::set_register(lengthv4f(vec));
        auto inputReg = Ops::set_register_each(vec.x, vec.y, vec.z, vec.w, 0, 0, 0, 0);
        auto result = Ops::div(inputReg, lengthReg);

        return Vec4f(
            Ops::materialize_register_at_index(result, 0),
            Ops::materialize_register_at_index(result, 1),
            Ops::materialize_register_at_index(result, 2),
            Ops::materialize_register_at_index(result, 3)
        );
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC4_AVX_FLOAT_INL