#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;


void replace(string &s, const string &oldVal, const string &newVal) {
    int i = 0;
    while (i < s.size()) {
        int i1 = i;

        int i2 = 0;
        while (i1 < s.size() && i2 < oldVal.size() && s[i1] == oldVal[i2] ) {
            ++i1;
            ++i2;
        }
        if (i2 == oldVal.size()) {
            s.replace(i, oldVal.size(), newVal);
            i+= newVal.size();

        } else {
            ++i;
        }
    }

}

int main()
{
    string s("I don't like it tho.");
    replace(s, "tho", "though");
    cout << s << endl;

    string s1("think it thru");
    replace(s1, "thru", "through");
    cout << s1 << endl;
    replace(s1, "thru", "through");
    cout << s1 << endl;

    string s2("tho thru tho thru th.");
    replace(s2, "tho", "though");
    cout << s2 << endl;

}
