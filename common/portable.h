

#ifndef _H_PORTABLE_
#define _H_PORTABLE_

#include <stdint.h>

//basic types
typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

typedef unsigned char uchar;
typedef signed char schar;
typedef wchar_t wchar;

// x86 and x86_64 types
#ifdef _M_X64
	#undef X86
	#define X64
#endif

#if defined(X86) || defined(__i386__) || defined(__i686__)
	typedef u32 unat;
#endif

#if defined(X64) || defined(__x86_64__)
	typedef u64 unat;
#endif

// Inline
#if DEBUG
	//force
	#define INLINE

	//sugest
	#define SINLINE

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	//force
	#define INLINE __forceinline
	//sugest
	#define SINLINE __inline
#else
	//force
	#define INLINE inline
	//sugest
	#define SINLINE inline
#endif

// No inline
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define NOINLINE __declspec(noinline)
#else
	#define NOINLINE noinline
#endif

// Fastcall
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define FASTCALL __fastcall
#else
	#define FASTCALL 

#endif

// Export
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define DLLEXPORT __declspec(dllexport)
	#define EXPORT extern "C" __declspec(dllexport)
	#define EXPORT_CALL __stdcall
	#define THREADCALL __stdcall
	#define CDECL __cdecl
#else
	#define DLLEXPORT

	#define EXPORT

	#define EXPORT_CALL

	#define THREADCALL

	#define CDECL

#endif

// Align
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define ALIGN_MEM(x) __declspec(align(x))
#else
	#define ALIGN_MEM(x) __attribute__((aligned(x)))
#endif

// length
#define WCHAR_LEN(X) sizeof(X) / sizeof(wchar_t)

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof(x[0]))

#endif


#if defined(_MSC_VER)
	#define DEBUG_BREAK __debugbreak()
#else
	#define DEBUG_BREAK __builtin_trap()
#endif


#if defined(_MSC_VER)
	#define NOOP __noop
#else
	#define NOOP(void)0
#endif
