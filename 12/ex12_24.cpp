#include <memory>
using std::make_shared;
using std::shared_ptr; using std::weak_ptr;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <exception>
using std::out_of_range;
#include <fstream>
using std::ifstream;

int main() {
    cout << "Input string length: ";
    size_t len;
    cin >> len;
    cin.ignore();
    char * ca = new char[len + 1];
    cin.get(ca, len + 1);
    cout << "The input string is: \n\"" << ca << "\"" << endl;
    delete[] ca;
    return 0;
}