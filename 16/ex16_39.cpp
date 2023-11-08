#include <iostream>
using std::cout; using std::endl;
#include <string>

template <typename T> int compare(const T &l, const T& r) {
    if (l < r) return -1;
    if (r < l) return 1;
    return 0;
}

int main() {
    cout << compare("aaa", "bbb") << endl;
    
    cout << compare<std::string>("aaa", "bb") << endl;
}