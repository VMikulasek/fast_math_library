#ifndef SIMD_OPERATIONS_AVX_FLOAT_HPP
#define SIMD_OPERATIONS_AVX_FLOAT_HPP

#include "./simd_operations_base.hpp"
#include "../vector/simd_vector_avx_float.hpp"

#include <immintrin.h>

namespace simd
{
    template<>
    class SIMDOperations<float, InstructionSet::AVX>
    {
    private:
        using NumType = float;
        static const InstructionSet INS_SET = InstructionSet::AVX;

        static __m256 op1Reg;
        static __m256 op2Reg;
        static __m256 resultReg;

    public:
        /**
         * @brief Loads vector of floats to float vector register
         * that represents operand 1
         * 
         * @param vector Vector of floats to load to register
         */
        static void load_op1(SIMDVector<NumType, INS_SET> &vector);

        /**
         * @brief Loads vector of floats to float vector register
         * that represents operand 2
         * 
         * @param vector Vector of floats to load to register
         */
        static void load_op2(SIMDVector<NumType, INS_SET> &vector);

        /**
         * @brief Loads 2 vectors of floats into 2 vector float registers
         * that represent both operands
         * 
         * @param vector1 Vector of floats to load to register representing op1
         * @param vector2 Vector of floats to load to register representing op2
         */
        static void load_ops(SIMDVector<NumType, INS_SET> &vector1, SIMDVector<NumType, INS_SET> &vector2);

        /**
         * @brief Stores result from register to memory and returns
         * wrapped in SIMDVector
         * 
         * @return SIMDVector<float, InstructionSet::AVX> Content of result register
         */
        static SIMDVector<NumType, INS_SET> get_result();

        /**
         * @brief Adds op1Reg and op2Reg and stores result into resultReg
         */
        static void add();

        /**
         * @brief Adds op1Reg and resultReg and stores result into resultReg
         */
        static void add_op1_result();

        /**
         * @brief Adds op2Reg and resultReg and stores result into resultReg
         */
        static void add_op2_result();

        /**
         * @brief Subtracts op2Reg from op1Reg and stores result into resultReg
         */
        static void sub();

        /**
         * @brief Subtracts op1Reg from resultReg and stores result into resultReg
         */
        static void sub_result_op1();

        /**
         * @brief Subtracts op2Reg from resultReg and stores result into resultReg
         */
        static void sub_result_op2();

        /**
         * @brief Multiplies op1Reg with op2Reg and stores result into resultReg
         */
        static void mul();

        /**
         * @brief Multiplies op1Reg with resultReg and stores result into resultReg
         */
        static void mul_op1_result();

        /**
         * @brief Multiplies op2Reg with resultReg and stores result into resultReg
         */
        static void mul_op2_result();

        /**
         * @brief Divides op1Reg by op2Reg and stores result into resultReg
         */
        static void div();

        /**
         * @brief Divides resultReg by op1Reg and stores result into resultReg
         */
        static void div_result_op1();

        /**
         * @brief Divides resultReg by op2Reg and stores result into resultReg
         */
        static void div_result_op2();
    };
}

#include "simd_operations_avx_float.inl"

#endif // SIMD_OPERATIONS_AVX_FLOAT_HPP