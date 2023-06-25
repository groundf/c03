#include <stdbool.h>

typedef struct result_t {
    bool valid;
    union {
        char * error;
        char * value; // todo generic
    };
} result_t1;
