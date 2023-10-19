#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include <stdexcept>
using std::runtime_error;

int main() {
    int n1, n2;
    while (cin >> n1 >> n2) {
        try {
            if (n2 == 0) {
                throw runtime_error("divide by zero");
            }
            cout << n1/n2 << endl;
        } catch (runtime_error e) {
            cout << e.what() << endl;
        }
        
    }
}