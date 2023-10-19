#include <memory>
using std::shared_ptr; using std::make_shared; using std::unique_ptr;
#include <iostream>
using std::cout; using std::endl;



int main() {
    unique_ptr<int> p;
    unique_ptr<int> p1(new int(5));
    // p = p1;
    // unique_ptr<int> p2(p1);
    // unique_ptr<int> p(42);
    return 0;
}