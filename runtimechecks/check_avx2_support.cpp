#include <stdio.h>

#if defined(_MSC_VER)
#include <intrin.h>

void cpuid(int cpuInfo[4], int function_id) {
    __cpuid(cpuInfo, function_id);
}

void cpuidex(int cpuInfo[4], int function_id, int subfunction_id) {
    __cpuidex(cpuInfo, function_id, subfunction_id);
}

#elif defined(__GNUC__) || defined(__clang__)
#include <cpuid.h>

void cpuid(int cpuInfo[4], int function_id) {
    __get_cpuid(function_id, (unsigned int*)&cpuInfo[0], (unsigned int*)&cpuInfo[1], (unsigned int*)&cpuInfo[2], (unsigned int*)&cpuInfo[3]);
}

void cpuidex(int cpuInfo[4], int function_id, int subfunction_id) {
    __cpuid_count(function_id, subfunction_id, cpuInfo[0], cpuInfo[1], cpuInfo[2], cpuInfo[3]);
}

#else
#error "Unsupported compiler"
#endif

int main()
{
    int cpuInfo[4];

    cpuidex(cpuInfo, 7, 0);
    int ebx = cpuInfo[1];
    int avx2Bit = 1 << 5;

    if ((ebx & avx2Bit) != 0)
    {
        // supports AVX2
        return 1;
    }

    // does not support AVX2
    return 0;
}