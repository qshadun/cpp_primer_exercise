#include <memory>
using std::shared_ptr;
#include <iostream>
using std::cout; using std::endl;

void process (shared_ptr<int> p) {

}

int main() {
    shared_ptr<int> p(new int(42));
    cout << *p << endl;
    // process(p);
    process(shared_ptr<int>(p.get()));
    cout << *p << endl;
}