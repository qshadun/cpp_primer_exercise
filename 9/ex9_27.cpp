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

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    forward_list<int> lst(ia, std::end(ia));
    auto prev = lst.before_begin();
    auto cur = lst.begin();
    for (; cur != lst.end();) {
        if (*cur % 2) {
            cur = lst.erase_after(prev);
        } else {
            prev = cur;
            ++cur;
        }
    }

    for (auto it = lst.cbegin(); it != lst.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;

    return 0;
}