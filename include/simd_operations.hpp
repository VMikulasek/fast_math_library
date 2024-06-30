#ifndef SIMD_OPERATIONS_HPP
#define SIMD_OPERATIONS_HPP

#include "simd_common.hpp"
#include "simd_vector.hpp"

#include <immintrin.h>

namespace simd
{
    template<typename T, InstructionSet S>
    class SIMDOperations;

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
        static void load_op1(SIMDVector<NumType, INS_SET> vector);

        /**
         * @brief Loads vector of floats to float vector register
         * that represents operand 2
         * 
         * @param vector Vector of floats to load to register
         */
        static void load_op2(SIMDVector<NumType, INS_SET> vector);

        /**
         * @brief Loads 2 vectors of floats into 2 vector float registers
         * that represent both operands
         * 
         * @param vector1 Vector of floats to load to register representing op1
         * @param vector2 Vector of floats to load to register representing op2
         */
        static void load_ops(SIMDVector<NumType, INS_SET> vector1, SIMDVector<NumType, INS_SET> vector2);

        /**
         * @brief Stores result from register to memory and returns
         * wrapped in SIMDVector
         * 
         * @return SIMDVector<float, InstructionSet::AVX> Content of result register
         */
        static SIMDVector<NumType, INS_SET> get_result();
    };
}

#include "../src/simd_operations.inl"

#endif // SIMD_OPERATIONS_HPP