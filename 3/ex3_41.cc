#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::begin;
using std::end;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> vi;
    
    for (int *p = begin(arr); p != end(arr); p++) {
        vi.push_back(*p);
    }
    for (int i : vi) {
        cout << i << " ";
    }
    cout << endl;

    int arr1[5];
    for (int i = 0; i < vi.size(); i++) {
        arr1[i] = vi[i];
    }
    for (int *p = begin(arr1); p != end(arr1); p++) {
        cout << *p << " ";
    }
    cout << endl;

    vector<int> vi2(begin(arr), begin(arr) + 3);
    for (int i : vi2) {
        cout << i << " ";
    }
    cout << endl;

}