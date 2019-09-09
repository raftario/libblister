// TODO: Add necessary imports

#import <ctype.h>
#import <string.h>


// TODO: Function definitions

void str_tolower(char* str) {
    for (unsigned int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}