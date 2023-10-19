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

#include <forward_list>
using std::forward_list;

forward_list<string>::iterator insert(forward_list<string> &flst, const string &first, const string &second)
{
    auto pFirst = flst.begin();
    for (auto it = flst.begin(); it != flst.end(); ++it)
    {
        pFirst = it;
        if (*it == first)
        {
            break;
        }
    }
    return flst.insert_after(pFirst, second);
}

int main()
{
    forward_list<string> flst{"aaa", "bbb", "ccc"};

    for (auto it = flst.cbegin(); it != flst.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    auto iter = insert(flst, "aaa", "ddd");

    cout << *iter << endl;

    for (auto it = flst.cbegin(); it != flst.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}