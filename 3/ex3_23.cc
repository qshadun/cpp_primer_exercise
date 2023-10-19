#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::toupper;


int main() {
    vector<int> vi = {1,2,3,4,5};
    for (auto it = vi.begin(); it != vi.end(); it++) {
        *it = *it * 2;
    }
    for (auto i : vi) {
        cout << i << endl;
    }
}