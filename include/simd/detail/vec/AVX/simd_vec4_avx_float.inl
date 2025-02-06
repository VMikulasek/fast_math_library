#ifndef SIMD_VEC4_AVX_FLOAT_INL
#define SIMD_VEC4_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec4_avx_float.hpp>

namespace simd
{
namespace avx
{
    inline Vec4f addv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

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

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::sub(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 4)
        );
    }

    inline Vec4f mulv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 4)
        );
    }

    inline Vec4f divv4f(const Vec4f &vec1, const Vec4f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::div(reg1, reg2);

        return Vec4f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 4)
        );
    }

    inline float dotv4f(const Vec4f &vec1, const Vec4f &vec2)
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

#endif // SIMD_VEC4_AVX_FLOAT_INL