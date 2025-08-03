#pragma once

#if defined(__clang__)
	#define _CLANG
#elif defined(_MSC_VER)
	#define _MSVC
#elif defined(__GNUC__)
	#define _GCC
#endif 

#define SSE_MAJOR 4
#define SSE_MINOR 2