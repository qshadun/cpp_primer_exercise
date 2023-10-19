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
    int nums[10];
    for (int i = 0; i < 10; i++) {
        nums[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int nums_cp[10];
    for (int i = 0; i < 10; i++) {
        nums_cp[i] = nums[i];
    }
    for (int i = 0; i < 10; i++) {
        cout << nums_cp[i] << " ";
    }
    cout << endl;
}