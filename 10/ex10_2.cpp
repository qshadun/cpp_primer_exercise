#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::count;

#include <sstream>
using std::istringstream;

#include <list>
using std::list;

int main() {
    string line;
    cout << "please input strings: ";
    getline(cin, line);
    istringstream iss(line);
    string s;
    list<string> ls;
    while (iss >> s) {
        ls.push_back(s);
    }

    string target;
    cout << "please input a target: ";
    cin >> target;
    int cnt = count(ls.begin(), ls.end(), target);
    cout << "there are " << cnt << " times of " << target << endl;

}