// TODO: Add necessary imports

#import <ctype.h>
#import <stdlib.h>
#import <string.h>

#import "gzip/zconf.h"
#import "gzip/zlib.h"


// TODO: Function definitions

void str_tolower(char* str) {
    for (unsigned int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

int decompress_gz_stream(char* compressed_stream, char* decompressed_stream) {
    size_t compressed_stream_length = strlen(compressed_stream);
    
    // If the compressed stream is 0 length, the decompressed stream is identical
    if (compressed_stream_length == 0)) {
        decompressed_stream = compressed_stream;
        return 0;
    }

    // Initial allocation of decompressed_stream
    decompressed_stream = (char*) malloc(compressed_stream_length);
    if (decompressed_stream == NULL) {
        return 1;
    }

    // Initialise z_stream
    z_stream stream;
    stream.next_in = (Bytef*) compressed_stream;
    stream.avail_in = compressed_stream_length;
    stream.total_out = 0;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;

    // Initialize inflation
    if (inflateInit2(&stream, (16 + MAX_WBITS)) != Z_OK)) {
        free(decompressed_stream);
        return 1;
    }

    // Store lengths for future reallocations
    size_t decompressed_stream_length = compressed_stream_length;
    size_t increase_length = decompressed_stream_length / 2;

    unsigned char done = 0;
    while (!done) {
        // Reallocate new memory if it runs out
        if (stream.totak_out >= decompressed_stream_length) {
            char* new_decompressed_stream = (char*) malloc(decompressed_stream_length + increase_length);
            if (new_decompressed_stream == NULL) {
                free(decompressed_stream);
                return 1;
            }
            memcpy(new_decompressed_stream, decompressed_stream, decompressed_stream_length);
            decompressed_stream_length += increase_length;
            free(decompressed_stream);
            decompressed_stream = new_decompressed_stream;
        }

        // Prepare for continuing inflation
        stream.next_out = (Bytef*) (decompressed_stream + stream.total_out);
        stream.avail_out = decompressed_stream_length - stream.total_out;

        // Continue inflation
        int e = inflate(&stream, Z_SYNC_FLUSH);
        if (e == Z_STREAM_END) {
            done = 1;
        } else if (e != Z_OK) {
            break;
        }
    }

    // Finish inflation
    if (inflateEnd(&stream) != Z_OK) {  
        free(decompressed_stream);
        return 1;
    }

    return 0;
}