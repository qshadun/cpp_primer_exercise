#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl;

int main() {
    vector<string> vs = {"1.2", "2", "3.3", "4"};
    double sum = 0;
    for (string s: vs) {
        sum += stod(s);
    }
    cout << sum << endl;
    cout << typeid(sum).name() << endl;
    return 0;
    
}