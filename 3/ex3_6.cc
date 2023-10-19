#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main() {
    string s("abcde");
    
    // for (auto &c : s) {
    //     c = 'x';
    // }
    // decltype(s.size()) i = 0;
    // while (i < s.size()) {
    //     s[i++] = 'x';
    // }
    for (decltype(s.size()) i = 0; i < s.size(); i++) {
        s[i] = 'x';
    }
    cout << s << endl;

    const string ss = "Keep Out";
    for (auto &c: ss) {
        cout << c << endl;
    }

    string sss;
    getline(cin, sss);
    string nopunc;
    for(auto c: sss) {
        if (!ispunct(c)) {
            nopunc += c;
        }
    }
    cout << nopunc << endl;

}