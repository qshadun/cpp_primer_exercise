#include <vector>
using std::vector; 
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

template <typename Iter>
void print(Iter beg, Iter end) {
    for (; beg != end; ++beg) {
        cout << *beg << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> v{1,2,3,4,5};
    print(v.begin(), v.end());

    list<string> l{"aa", "bc", "de"};
    print(l.begin(), l.end());
}