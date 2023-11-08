#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

template<typename T, size_t N> void print(const T (&arr)[N]) {
    for (size_t i = 0; i != N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    
    print({1,2,3,4,5});
    double d[5]{1.,2.,3.};
    print(d);
}