#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;


void replace(string &s, const string &oldVal, const string &newVal) {
    auto it = s.begin();
    while (it!=s.end()) {
        auto it1 = it;
        auto it2 = oldVal.begin();
        while (it1 != s.end() && it2 != oldVal.end() && *it1 == *it2 ) {
            ++it1;
            ++it2;
        }
        if (it2 == oldVal.end()) {
            it = s.erase(it, it1);
            it = s.insert(it, newVal.begin(), newVal.end());
            it += newVal.size();

        } else {
            ++it;
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
}
