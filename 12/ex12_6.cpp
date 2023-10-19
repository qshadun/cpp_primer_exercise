#include <memory>
using std::shared_ptr;
#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <vector>
using std::vector;

vector<int> * create() {
    return new vector<int>();
}

void readNumbers(vector<int> *vi) {
    int i;
    while (cin >> i) {
        vi->push_back(i);
    }
}

void printNumbers(vector<int> *vi) {
    for (auto num: *vi) {
        cout << num << ' ';
    }
    cout << endl;
}

int main() {
    auto p = create();
    readNumbers(p);
    printNumbers(p);
    delete p;
}