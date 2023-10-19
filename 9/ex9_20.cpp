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
    list<int> ls;
    string line;
    getline(cin, line);
    istringstream iss(line);
    int i;
    while (iss >> i) {
        ls.push_back(i);
    }

    for (auto it = ls.cbegin(); it != ls.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    deque<int> odd;
    deque<int> even;
    
    for (auto it = ls.cbegin(); it != ls.cend(); ++it) {
        if (*it %2 == 0) {
            even.push_back(*it);
        } else {
            odd.push_back(*it);
        }
    }
    cout << "odd: ";
    for (auto it = odd.cbegin(); it != odd.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    cout << "even: ";
    for (auto it = even.cbegin(); it != even.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}