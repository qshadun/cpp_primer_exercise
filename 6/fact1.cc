#include "chapter_6.h"

int fact(unsigned int n) {
    unsigned int result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}