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
        static __m256 op1;
        static __m256 op2;

        static __m256 result;

    public:
        /**
         * @brief Loads vector of floats to float vector register
         * that represents operand 1
         * 
         * @param vector Vector of floats to load to register
         */
        static void load_op1(SIMDVector<float, InstructionSet::AVX> vector);

        /**
         * @brief Loads vector of floats to float vector register
         * that represents operand 2
         * 
         * @param vector Vector of floats to load to register
         */
        static void load_op2(SIMDVector<float, InstructionSet::AVX> vector);

        /**
         * @brief Loads 2 vectors of floats into 2 vector float registers
         * that represent both operands
         * 
         * @param vector1 Vector of floats to load to register representing op1
         * @param vector2 Vector of floats to load to register representing op2
         */
        static void load_ops(SIMDVector<float, InstructionSet::AVX> vector1, SIMDVector<float, InstructionSet::AVX> vector2);

        /**
         * @brief Stores result from register to memory and returns
         * wrapped in SIMDVector
         * 
         * @return SIMDVector<float, InstructionSet::AVX> Content of result register
         */
        static SIMDVector<float, InstructionSet::AVX> get_result();
    };
}

#include "../src/simd_operations.inl"

#endif // SIMD_OPERATIONS_HPP