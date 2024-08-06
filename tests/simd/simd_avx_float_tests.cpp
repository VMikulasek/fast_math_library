#include <gtest/gtest.h>
#include <simd/simd_vector.hpp>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>
#include <tests_common.hpp>
#include <functional>

namespace tests
{
    class SimdAvxFloatTest : public testing::Test
    {
    protected:

        using Vec = simd::SIMDVector<float, simd::AVX>;
        using Ops = simd::SIMDOperations<float, simd::AVX>;

        const unsigned VECTOR_LEN = 8;

        Ops::AvxReg reg1;
        Ops::AvxReg reg2;
        Ops::AvxReg resultReg;

        const Vec basicVec1{ 1, 1, 1, 1, 1, 1, 1, 1 };
        const Vec basicVec2{ 2, 2, 2, 2, 2, 2, 2, 3 };
        const Vec decimalVec1 { 1.543, 1.2, 1.134, 1.3, 1.5, 1.13413, 1.1, 1.0 };
        const Vec decimalVec2 { 2.1, 2.2, 2.3, 2.1341, 2.341, 2.34, 2.1324, 3.1431 };
        const Vec negativeVec1 { 1.2, 1.1, 1.2, 1.1, 1.2, 1.1, 1.2, 1.1 };
        const Vec negativeVec2 { -2.1, -2.2, -2.1, -2.2, -2.1, -2.2, -2.1, -3.2 };
        const Vec zerosVec { 0, 0, 0, 0, 0, 0, 0, 0 };
        const Vec bigNumsVec1 { 134541516143341341534.1, 35736435.0, 674674763465.0, 145598647.3, 354.2, 12413451.1324, 134134112141.12, 123341.1341 };
        const Vec bigNumsVec2 { 1341431.0, 1344313414.0, 13416463.0, 425245264512341341.0, 56335763424522452.0, 76859757.44, 467365573.245, 1341334124351265685.56535 };


        Vec usedVec1;
        Vec usedVec2;

        void SetRegisters(const Vec &vec1, const Vec &vec2)
        {
            reg1 = Ops::load_vector(vec1);
            reg2 = Ops::load_vector(vec2);

            usedVec1 = vec1;
            usedVec2 = vec2;
        }

        void CheckResult(std::function<float(float, float)> operation)
        {
            Vec resultVec = Ops::materialize_register(resultReg);
            const float *result = resultVec.get_content();

            const float *vec1Content = usedVec1.get_content();
            const float *vec2Content = usedVec2.get_content();

            for (unsigned i = 0; i < VECTOR_LEN; i++)
            {
                float expected = operation(vec1Content[i], vec2Content[i]);

                // cast to int to compare bitwise, to dodge NaN non equality
                int expectedI = *reinterpret_cast<int *>(&expected);
                int resultI = *reinterpret_cast<const int *>(&(result[i]));

                EXPECT_EQ(resultI, expectedI);
            }
        }
    };

    TEST_F(SimdAvxFloatTest, LoadStore)
    {
        const unsigned avxFloatVectorSize = 8;
        const float testVal = 2;
        simd::SIMDVector<float, simd::AVX> vec(
            testVal, testVal, testVal, testVal,
            testVal, testVal, testVal, testVal
        );
        
        simd::SIMDOperations<float, simd::AVX>::AvxReg reg = simd::SIMDOperations<float, simd::AVX>::load_vector(vec);
        vec = simd::SIMDOperations<float, simd::AVX>::materialize_register(reg);
        const float *content = vec.get_content();

        for (unsigned i = 0; i < 8; i++)
        {
            EXPECT_FLOAT_EQ(content[i], 2);
        }
    }

    TEST_F(SimdAvxFloatTest, AddBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }

    TEST_F(SimdAvxFloatTest, SubBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }

    TEST_F(SimdAvxFloatTest, MulBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulDecimalZeros)
    {
        SetRegisters(decimalVec1, zerosVec);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }

    TEST_F(SimdAvxFloatTest, DivBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivDecimalZeros)
    {
        SetRegisters(decimalVec1, zerosVec);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }

    TEST_F(SimdAvxFloatTest, And1)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, And2)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, And3)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, AndZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, And4)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }

    TEST_F(SimdAvxFloatTest, Or1)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, Or2)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, Or3)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, OrZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, Or4)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }

    TEST_F(SimdAvxFloatTest, Xor1)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, Xor2)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, Xor3)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, XorZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, Xor4)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }

    TEST_F(SimdAvxFloatTest, LTAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }
    TEST_F(SimdAvxFloatTest, LTAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }
    TEST_F(SimdAvxFloatTest, LTAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }
    TEST_F(SimdAvxFloatTest, LTMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }

    TEST_F(SimdAvxFloatTest, GTAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }
    TEST_F(SimdAvxFloatTest, GTAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }
    TEST_F(SimdAvxFloatTest, GTAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }
    TEST_F(SimdAvxFloatTest, GTMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }

    TEST_F(SimdAvxFloatTest, EQAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }
    TEST_F(SimdAvxFloatTest, EQAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }
    TEST_F(SimdAvxFloatTest, EQAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }
    TEST_F(SimdAvxFloatTest, EQMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }

    TEST_F(SimdAvxFloatTest, LEAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }
    TEST_F(SimdAvxFloatTest, LEAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }
    TEST_F(SimdAvxFloatTest, LEAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }
    TEST_F(SimdAvxFloatTest, LEMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }

    TEST_F(SimdAvxFloatTest, GEAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
    TEST_F(SimdAvxFloatTest, GEAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
    TEST_F(SimdAvxFloatTest, GEAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
    TEST_F(SimdAvxFloatTest, GEMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
}