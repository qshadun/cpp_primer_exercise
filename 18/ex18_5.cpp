#include <iostream>
#include <exception>
using namespace std;
#include <cstdlib>

int main() {
    try {
        int i = 0;
        throw runtime_error("aaa");
    } catch (exception &e) {
        cout << e.what() << endl;
        abort;
    }
}