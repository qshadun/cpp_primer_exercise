#include<string>
#include<vector>
#include<iostream>
#include <algorithm>
#include <sstream>
#include <iterator>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;


int main() {
    vector<vector<int> > ivec;
    // vector<string> svec = ivec;
    vector<string> svec(10, "null");

    for(auto ele : svec) {
        cout << ele << ",";
    }
    cout << endl;

    
}