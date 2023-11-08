#include <vector>
using std::vector; 
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

template <typename C>
void print(const C &c) {
    for (typename C::size_type i = 0; i != c.size(); ++i) {
        cout << c[i] << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> v{1,2,3,4,5};
    print(v);

    // list<string> l{"aa", "bc", "de"};
    // print(l);
}