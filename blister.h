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

#define BLISTER_OK 0
#define BLISTER_ALLOCATION 1
#define BLISTER_INFLATION 2
#define BLISTER_MAGIC 3
#define BLISTER_FILE 3

#define BLISTER_VERIFY_ALLOC(var) if (var == NULL) return BLISTER_ALLOCATION


// TODO: Add necessary imports

#include "json/cJSON.h"

// TODO: Function declarations

void str_tolower(char* str);
int decompress_gz_stream(char* compressed_stream, char* decompressed_stream);
int blist_file_to_gz_stream(char* filename, char* stream);
cJSON* parse_blist_file(char* src);


#ifdef __cplusplus
}
#endif

#endif
