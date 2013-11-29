

#ifndef _H_PORTABLE_
#define _H_PORTABLE_

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

//no inline :)
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define NOINLINE __declspec(noinline)
#else
	#define NOINLINE noinline
#endif


#endif
