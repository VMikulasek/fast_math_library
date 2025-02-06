#ifndef SIMD_VEC2_AVX_FLOAT_INL
#define SIMD_VEC2_AVX_FLOAT_INL

#include <simd/detail/vec/AVX/simd_vec2_avx_float.hpp>
#include <iostream>

namespace simd
{
namespace avx
{
    inline Vec2f addv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, 0, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, 0, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::add(reg1, reg2);

        std::cout << "reg1 " << Ops::materialize_register_at_index(reg1, 0) << std::endl;
        std::cout << "reg2 " << Ops::materialize_register_at_index(reg2, 0) << std::endl;
        std::cout << "resReg " << Ops::materialize_register_at_index(resReg, 0) << std::endl;

        return Vec2f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1)
        );
    }

    inline Vec2f subv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, 0, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, 0, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::sub(reg1, reg2);

        return Vec2f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1)
        );
    }

    inline Vec2f mulv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, 0, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, 0, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);

        return Vec2f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1)
        );
    }

    inline Vec2f divv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, 0, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, 0, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::div(reg1, reg2);

        return Vec2f(
            Ops::materialize_register_at_index(resReg, 0),
            Ops::materialize_register_at_index(resReg, 1)
        );
    }

    inline float dotv2f(const Vec2f &vec1, const Vec2f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::AvxReg reg1 = Ops::set_register_each(vec1.x, vec1.y, 0, 0, 0, 0, 0, 0);
        Ops::AvxReg reg2 = Ops::set_register_each(vec2.x, vec2.y, 0, 0, 0, 0, 0, 0);

        Ops::AvxReg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC2_AVX_FLOAT_INL