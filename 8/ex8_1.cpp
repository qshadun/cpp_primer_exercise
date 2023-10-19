#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <string>
using std::string;

std::istream& read(std::istream& is) {
    string s;
    while (is >> s) {
        cout << s << ' ';
    }
    cout << endl;
    is.clear();
    return is;
}

int main(){
    read(cin);
    return 0;
}