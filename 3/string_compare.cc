#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    bool eq = s1 == s2;
    cout << s1 << " " << s2 << " " << eq << endl;
    if (s1.size() == s2.size()) {
        cout << "same size" << endl;
    } else if (s1.size() < s2.size()) {
        cout << "s2 is longer" << endl;
    } else {
        cout << "s1 is longer" << endl;
    }


    return 0;
}