#include "chapter_6.h"

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main() {
    unsigned int n;
    cout << "please input a number: ";
    while (cin >> n) {
        cout << fact(n) << endl;
        cout << "please input a number: ";
    }
}
