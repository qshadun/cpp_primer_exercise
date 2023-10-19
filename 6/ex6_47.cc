#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl; using std::cin;

void printVecRec(const vector<int>::iterator beg, const vector<int>::iterator end) {
    #ifndef NDEBUG
        cout << "In function: " << __func__ << ' ' << "Vector size: " << end - beg << endl;
    #endif
    if (beg == end) {
        cout << endl;
        return;
    }

    cout << *beg << endl;
    printVecRec(beg + 1, end);
}

int main() {
    vector<int> vi;
    for (int i = 0; i != 10; ++i) {
        vi.push_back(i);
    }
    printVecRec(vi.begin(), vi.end());
}