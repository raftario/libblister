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

#include "json/cJSON.h"

// TODO: Function declarations

void str_tolower(char* str);
int decompress_gz_stream(char* compressed_stream, char* decompressed_stream);
char* blist_file_to_gz_stream(char* src);
cJSON* parse_blist_file(char* src);


#ifdef __cplusplus
}
#endif

#endif
