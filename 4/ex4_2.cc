#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

int main() {
    vector<int> vec = {1,2,3,4,5};
    cout << * (vec.begin()) << endl;

    cout << * (vec.begin() + 1) << endl;
}