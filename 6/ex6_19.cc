#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

int count(const string &s, char c) {
    int result = 0;
    for (auto cc: s) {
        if (cc == c) {
            ++result;
        }
    }
    return result;
}

int sum(vector<int>::iterator beg, vector<int>::iterator end, int i) {
    cout << *(beg + i) << endl;
}
int main() {
    
    cout << count("abacde", 'a') << endl;
    vector<int> vec(10);
    for (int i = 0; i != 10; ++i) {
        vec[i] = i;
    }
    sum(vec.begin(), vec.end(), 3);
}