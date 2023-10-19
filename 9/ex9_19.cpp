#include <string>
using std::string;
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;using std::endl; using std::cin; using std::getline;
#include <deque>
using std::deque;
#include <sstream>
using std:: istringstream;

int main() {
    list<string> ls;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        ls.push_back(word);
    }

    for (auto it = ls.cbegin(); it != ls.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}