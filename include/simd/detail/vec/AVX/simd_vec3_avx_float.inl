#ifndef SIMD_VEC3_AVX_FLOAT_INL
#define SIMD_VEC3_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec3_avx_float.hpp>

namespace simd
{
namespace avx
{
    inline Vec3f addv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::add(reg1, reg2);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }

    inline Vec3f subv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::sub(reg1, reg2);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }

    inline Vec3f mulv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }

    inline Vec3f divv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::div(reg1, reg2);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }

    inline Vec3f absv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::abs(reg);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }
    inline Vec3f minv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::min(reg1, reg2);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }
    inline Vec3f maxv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::max(reg1, reg2);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }

    inline Vec3f fast_sqrtv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg;
        mathops::avx::_fast_invsqrt_arr8(vec.data, resReg);
        Ops::AvxReg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }
    inline Vec3f fast_invsqrtv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg = Ops::set_register_each(vec.x, vec.y, vec.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg;
        mathops::avx::_fast_invsqrt_arr8(vec.data, resReg);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2)
        );
    }

    inline float dotv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC3_AVX_FLOAT_INL