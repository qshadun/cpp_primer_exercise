#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <list>
using std::list;

template <typename Iter, typename Val> Iter find_elem(Iter begin, Iter end, const Val& target) {
    for(; begin != end; ++begin) {
        if (*begin == target) return begin;
    }
    return begin;
}

int main() {
    vector<int> vi{1,2,3,4,5};
    auto it1 =  find_elem(vi.begin(), vi.end(), 3);
    if (it1 != vi.end()) cout << *it1 << endl;

}