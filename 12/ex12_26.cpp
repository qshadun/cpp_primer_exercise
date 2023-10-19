#include <memory>
using std::make_shared;
using std::shared_ptr; using std::weak_ptr;
using std::allocator;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <exception>
using std::out_of_range;
#include <fstream>
using std::ifstream;

int main() {
    size_t n = 5;
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    string *q = p;
    while ( q != p + n && cin >> s) {
        alloc.construct(q++, s);
    }
    size_t sz = q - p;
    for (auto *pp = p; pp != q; ++pp) {
        cout << *pp << ' ';
    }
    cout << endl;
    while (q != p) {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, n);
    return 0;
}