#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

vector<int>::iterator find(vector<int>::iterator beg, vector<int>::iterator end, const int target) {
    while (beg != end) {
        if (*beg == target) {
            return beg;
        }
        ++beg;
    }
    return end;
}

int main() {
    vector<int> vi = {1,2,3,4,5};
    auto iter = find(vi.begin(), vi.end(), 3);
    if (iter != vi.end()) {
        cout << "found at index " << iter - vi.begin() << endl;
    } else {
        cout << "not found" << endl;
    }
    
    iter = find(vi.begin() + 3, vi.end(), 3);
    if (iter != vi.end()) {
        cout << "found at index " << iter - vi.begin() << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}