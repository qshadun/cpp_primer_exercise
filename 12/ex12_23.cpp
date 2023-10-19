#include <memory>
using std::make_shared;
using std::shared_ptr; using std::weak_ptr;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <exception>
using std::out_of_range;
#include <fstream>
using std::ifstream;

int main() {
    char *c1 = "Hello ";
    char *c2 = "World!";
    char *c3 = new char[std::strlen(c1) + std::strlen(c1) + 1];
    std::strcpy(c3, c1);
    std::strcat(c3, c2);
    cout << c3 << endl;
    delete[] c3;

    string s1 = "Hello ";
    string s2 = "World!";
    string s3 = s1 + s2;
    cout << s3 << endl;
}