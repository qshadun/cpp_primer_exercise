#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout; using std::endl;

#include "chapter_6.h"

int main() {
    for (size_t i = 0; i != 10; i++) {
        cout << f() << endl;
    }
}

int f() {
    static size_t count = 0;
    return count++;
}
