#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::toupper;

#include <cstring>
using std::strcat;
using std::strcpy;

int main() {
    char s1[] = "Hello";
    char s2[] = " World!";
    unsigned total = (sizeof(s1) + sizeof(s2) - 1) / sizeof(char);
    char larger[total];
    strcpy(larger, s1);
    strcat(larger, s2);

    cout << larger << endl;

    cout << sizeof(s1) << " " << sizeof(s2) << " " << sizeof(larger) << endl; 
}