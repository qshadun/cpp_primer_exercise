#include <string>
using std::string;
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
#include <deque>
using std::deque;
#include <sstream>
using std::istringstream;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    list<int> il(ia, std::end(ia));
    for (auto it = il.cbegin(); it != il.cend();)
    {
        if (*it % 2 != 0) {
            it = il.erase(it);
        } else {
            ++it;
        }
    }
    
    for (auto it = il.cbegin(); it != il.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    vector<int> iv(ia, std::end(ia));
    for (auto it = iv.cbegin(); it != iv.cend();)
    {
        if (*it % 2 == 0) {
            it = iv.erase(it);
        } else {
            ++it;
        }
    }
    
    for (auto it = iv.cbegin(); it != iv.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}