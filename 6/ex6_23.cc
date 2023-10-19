#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

void print(const char *cp) {
    if (cp) {
        while (*cp) {
            cout << *cp;
        }
        cout << endl;
    }
}

void print(const int *beg, const int *end) {
    while (beg != end) {
        cout << *beg++ << ' ';
    }
    cout << endl;
}

void print(std::vector<int>::const_iterator beg,
           std::vector<int>::const_iterator end) {
            for (auto ptr = beg; ptr != end; ++ptr) {
                cout << *ptr << ' ';
            }
            cout << endl;
           }

void print(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << ' ';
    }
    cout << endl;
}

void print(const std::vector<int>& vec) {
    for (auto i : vec) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int i = 0, j[2] = {0, 1};
    vector<int> vec = {0, 1, 2};
    print(j, j+2);
    print(vec.begin(), vec.end());
    print(j, 2);
    print(vec);
}