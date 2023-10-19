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
    auto iter = vi.begin(); // callbegin,notcbeginbecausewe’rechangingvi
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter); // duplicate the current element
            iter += 2;
        }
        else
        { // advance past this element and the one inserted before it
            iter = vi.erase(iter);
        } // remove even elements
        // don’t advance the iterator; iter denotes the element after the one we erased
    }
    for (auto it = vi.begin(); it != vi.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void try_list() {
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = li.begin(); // callbegin,notcbeginbecausewe’rechangingvi
    while (iter != li.end())
    {
        if (*iter % 2)
        {
            iter = li.insert(iter, *iter); // duplicate the current element
            ++iter;
            ++iter;
        }
        else
        { // advance past this element and the one inserted before it
            iter = li.erase(iter);
        } // remove even elements
        // don’t advance the iterator; iter denotes the element after the one we erased
    }

    for (auto it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void try_forward_list() {
    forward_list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = li.before_begin();
    auto iter = li.begin(); // callbegin,notcbeginbecausewe’rechangingvi
    while (iter != li.end())
    {
        if (*iter % 2)
        {
            iter = li.insert_after(iter, *iter); // duplicate the current element
            prev = iter;
            ++iter;
        }
        else
        { // advance past this element and the one inserted before it
            iter = li.erase_after(prev);
        } // remove even elements
        // don’t advance the iterator; iter denotes the element after the one we erased
    }

    for (auto it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    try_vector();
    try_list();
    try_forward_list();
}
