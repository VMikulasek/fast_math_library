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

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::add(reg1, reg2);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f subv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::sub(reg1, reg2);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f mulv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::mul(reg1, reg2);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f divv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::div(reg1, reg2);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f absv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        Ops::Reg resReg = Ops::abs(reg);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec3f minv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::min(reg1, reg2);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec3f maxv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::max(reg1, reg2);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f fast_sqrtv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        Ops::Reg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);
        Ops::Reg oneReg = Ops::set_register(1.f);
        resReg = Ops::div(oneReg, resReg);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec3f fast_invsqrtv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        Ops::Reg resReg;
        mathops::avx::_fast_invsqrt_arr8(reg, resReg);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f fast_sinv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);
        
        Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::Reg resReg = mathops::avx::_fast_sin_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }
    inline Vec3f fast_cosv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);
        
        Ops::Reg AVec, BVec, CVec, pi2Vec, quarter;
        mathops::avx::_init_sincos_constants(AVec, BVec, CVec, pi2Vec, quarter);
        Ops::Reg resReg = mathops::avx::_fast_cos_arr8(reg, pi2Vec,
            quarter, AVec, BVec, CVec);

        Vec3f res;
        Ops::materialize_register(resReg, res.data);
        return res;
    }

    inline Vec3f crossv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg vec1Mul1 = Ops::load_vector(vec1.data);
        Ops::Reg vec2Mul1 = Ops::set_register_each(vec2.y, vec2.z, vec2.x, 0, 0, 0, 0, 0);
        Ops::Reg vec1Mul2 = Ops::set_register_each(vec1.y, vec1.z, vec1.x, 0, 0, 0, 0, 0);
        Ops::Reg vec2Mul2 = Ops::load_vector(vec2.data);

        Ops::Reg firstProduct = Ops::mul(vec1Mul1, vec2Mul1);
        Ops::Reg secondProduct = Ops::mul(vec1Mul2, vec2Mul2);

        Ops::Reg resReg = Ops::sub(firstProduct, secondProduct);

        return Vec3f(
            Ops::materialize_register_at_index(resReg, 1),
            Ops::materialize_register_at_index(resReg, 2),
            Ops::materialize_register_at_index(resReg, 0)
        );
    }
    inline float dotv3f(const Vec3f &vec1, const Vec3f &vec2)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg1 = Ops::load_vector(vec1.data);
        Ops::Reg reg2 = Ops::load_vector(vec2.data);

        Ops::Reg resReg = Ops::mul(reg1, reg2);
        resReg = Ops::horizontal_add(resReg, resReg);
        resReg = Ops::horizontal_add(resReg, resReg);

        return Ops::materialize_register_at_index(resReg, 0);
    }
    inline float lengthv3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        Ops::Reg reg = Ops::load_vector(vec.data);

        reg = Ops::mul(reg, reg);
        reg = Ops::horizontal_add(reg, reg);
        reg = Ops::horizontal_add(reg, reg);

        return mathops::sqrt(Ops::materialize_register_at_index(reg, 0));
    }
    inline Vec3f normalizev3f(const Vec3f &vec)
    {
        using Ops = SIMDOperations<float, InstructionSet::AVX>;

        auto lengthReg = Ops::set_register(lengthv3f(vec));
        auto inputReg = Ops::load_vector(vec.data);
        auto result = Ops::div(inputReg, lengthReg);

        Vec3f res;
        Ops::materialize_register(result, res.data);
        return res;
    }
} // namespace avx
} // namespace simd

#endif // SIMD_VEC3_AVX_FLOAT_INL