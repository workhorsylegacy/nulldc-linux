

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

#ifdef X86
	typedef u32 unat;
#endif

#ifdef X64
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
