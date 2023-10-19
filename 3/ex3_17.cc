#include<string>
#include<vector>
#include<iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::toupper;


int main() {
    vector<string> vs;
    string s;
    while(cin >> s) {
        vs.push_back(s);
    }
    int count = 0;
    for (auto s: vs) {
        for (auto &c: s) {
            c = toupper(c);
        }
        cout << s << " ";
        count += 1;
        if (count % 8 == 0) {
            cout << endl;
        }

    }
    cout << endl;
    
}