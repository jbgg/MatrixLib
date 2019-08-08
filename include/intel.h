/* intel.h */

#ifndef __INTEL_H__
#define __INTEL_H__

#define CPUID01_ECX_SSE3        (1 <<  0)
#define CPUID01_ECX_PCLMULQDQ   (1 <<  1)
#define CPUID01_ECX_SSSE3       (1 <<  9)
#define CPUID01_ECX_FMA         (1 << 12)
#define CPUID01_ECX_SSE41       (1 << 19)
#define CPUID01_ECX_SSE42       (1 << 20)
#define CPUID01_ECX_AESNI       (1 << 25)
#define CPUID01_ECX_OSXSAVE     (1 << 27)
#define CPUID01_ECX_AVX         (1 << 28)
#define CPUID01_ECX_F16C        (1 << 29)

#define CPUID07_00_EBX_AVX2     (1 <<  5)
#define CPUID07_00_EBX_AVX512F  (1 << 16)

#define XCR0_SSE                (1 << 1)
#define XCR0_AVX                (1 << 2)

#endif /* __INTEL_H__ */

