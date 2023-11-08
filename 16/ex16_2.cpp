#include <iostream>
using std::cout; using std::endl;

template <typename T> int compare(const T &l, const T& r) {
    if (l < r) return -1;
    if (r < l) return 1;
    return 0;
}

int main() {
    cout << compare(1, 2) << endl;
    cout << compare(11.2, 2.) << endl;

}