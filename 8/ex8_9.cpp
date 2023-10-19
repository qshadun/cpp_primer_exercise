#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <sstream>

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
    std::istringstream iss("a b c d e");
    read(iss);
    return 0;
}