#ifndef blister
#define blister

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#ifdef __WINDOWS__
#define BLISTER_PUBLIC(type) __declspec(dllexport) type __stdcall
#else
#define BLISTER_PUBLIC(type) type
#endif


// TODO: Add necessary imports


// TODO: Function declarations

void str_tolower(char* str);


#ifdef __cplusplus
}
#endif

#endif
