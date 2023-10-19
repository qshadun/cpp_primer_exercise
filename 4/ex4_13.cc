#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main() {
    int i;
    double d;
    i = d = 3.5;
    cout << d << endl;
    cout << i << endl;
 
    // if (i = 42) {
    //     cout << 42 << endl;
    // }
    double dval; int ival;
    dval = ival = 0;
    int *pi;
    pi = &ival;
    
    cout << dval << endl;
    cout << ival << endl;
    cout << *pi << endl;

    vector<string> vs = {"aa", "", "bb", "","cc"};
    auto iter = vs.begin();
    cout << *iter++ << endl;

    cout << iter -> empty() << endl;

    cout << iter++ -> empty() << endl;

    string s = "word";
    string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
}