#ifndef SIMD_VEC3_AVX_FLOAT_INL
#define SIMD_VEC3_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec3_avx_float.hpp>

namespace simd
{
namespace avx
{
    Vec3f addv3f(const Vec3f &vec1, const Vec3f &vec2)
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

    Vec3f subv3f(const Vec3f &vec1, const Vec3f &vec2)
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

    Vec3f mulv3f(const Vec3f &vec1, const Vec3f &vec2)
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

    Vec3f divv3f(const Vec3f &vec1, const Vec3f &vec2)
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

    float dotv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, vec1.z, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, vec2.z, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);
        Ops::AvxReg resReg = Ops::horizontal_add(resReg, resReg);
        Ops::AvxReg resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC3_AVX_FLOAT_INL