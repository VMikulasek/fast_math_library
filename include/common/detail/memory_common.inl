#ifndef MEMORY_COMMON_INL
#define MEMORY_COMMON_INL

#include <cstddef>
#include <cstdlib> // std::aligned_alloc

#if defined(_MSC_VER)
#include <malloc.h> // _aligned_malloc
#endif // _MSC_VER

#define ALLOC_DST                                                                     \
    float *dst = _alloc_aligned_memory_float(size * sizeof(float), AVX_ALIGNMENT);      \
    if (dst == nullptr)                                                                 \
    {                                                                                   \
        return nullptr;                                                                 \
    }                                                                                   \
    do; while (false)

inline void *_alloc_aligned_memory(size_t size, int alignment)
{
#if defined(_MSC_VER)
        return _aligned_malloc(size, alignment);
#else // _MSC_VER
        return std::aligned_alloc(alignment, size);
#endif // _MSC_VER
}

inline float *_alloc_aligned_memory_float(size_t size, int alignment)
{
    return reinterpret_cast<float *>(_alloc_aligned_memory(size, alignment));
}

inline void _free_aligned_memory(void *mem)
{
#if defined(_MSC_VER)
        return _aligned_free(mem);
#else // _MSC_VER
        return std::free(mem);
#endif // _MSC_VER
}

#endif // MEMORY_COMMON_HPP