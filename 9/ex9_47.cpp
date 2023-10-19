#include <string>
using std::string;

#include <iostream>
using std::cout;using std::endl;

int main(){
    string s = "ab2c3d7R4E6";
    string numbers = "123456789";
    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
        cout << "found digits at index : " << pos << ", element is: " << s[pos] << endl;
        ++pos; 
    }

    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
        cout << "found alphabet at index : " << pos << ", element is: " << s[pos] << endl;
        ++pos; 
    }

}