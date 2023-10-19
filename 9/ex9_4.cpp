#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

bool find(std::vector<int>::iterator beg, std::vector<int>::iterator end, const int target) {
    while (beg != end) {
        if (*beg == target) {
            return true;
        }
        ++beg;
    }
    return false;
}

int main() {
    vector<int> vi = {1,2,3,4,5};
    cout << find(vi.begin(), vi.end(), 3) << endl;
    cout << find(vi.begin() + 3, vi.end(), 3) << endl;
    return 0;
}