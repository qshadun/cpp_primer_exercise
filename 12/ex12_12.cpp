#include <memory>
using std::shared_ptr; using std::make_shared;
#include <iostream>
using std::cout; using std::endl;

void process (shared_ptr<int> p) {

}

int main() {
    auto p = new int(1);
    auto sp = make_shared<int>(2);
    //process(p);
    // process(new int());
    process(sp);
    cout << *sp << endl;
    cout << *p << endl;
    process(shared_ptr<int>(p));
    cout << *p << endl;
}