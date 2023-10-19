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

void try_vector() {
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = vi.begin();
   
    while (begin != vi.end())
    {
        ++begin;
        begin = vi.insert(begin, 42);
        ++begin;
    }
    for (auto it = vi.begin(); it != vi.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    try_vector();
    return 0;
}
