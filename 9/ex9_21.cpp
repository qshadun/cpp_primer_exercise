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
    vector<int> iv{1, 2, 3, 4, 5};
    int some_val = 2;
    vector<int>::iterator iter = iv.begin(),
                          mid = iv.begin() + iv.size() / 2;
    while (iter != iv.begin() + iv.size() / 2)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val);
            ++iter;
        }
        ++iter;
    }
    for (auto it = iv.cbegin(); it != iv.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
}