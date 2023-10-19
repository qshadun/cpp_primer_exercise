#include <string>
using std::string;
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;using std::endl;


int main() {
    list<char *> ls = {"aa", "bb", "cc"};
    for (char *s: ls) {
        cout << s << ' ';
    }
    cout << endl;

    vector<string> vs(ls.begin(), ls.end());
    for (string s: vs) {
        cout << s << ' ';
    }
    cout << endl;

    list<string> lss(vs.begin(), vs.begin() + 2);
    for (string s: lss) {
        cout << s << ' ';
    }
    cout << endl;
}