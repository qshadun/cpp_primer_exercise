
#include <unordered_map>
using std::unordered_map;

#include <map>
using std::map; using std::multimap;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <set>
using std::set;

#include <string>
using std::string; 

using std::hash;

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;

#include <cstddef>
using std::size_t;

#include <vector>
using std::vector;
using std::make_pair;

#include <algorithm>


// unordered_map version of the word count program
int main() 
{
	multimap<string, string> authors{
        {"Brian, Jordan", "A Book 2"}, 
        {"Benjamin, Bob", "Yet Another Book"},
        {"Benjamin, Bob", "Another Book"},
        {"Brian, Jordan", "A Book 1"},
        {"Rob, Tuner", "What's this?"},
    };

    set<string> uniqAuthors;
    for (auto &a: authors) {
        uniqAuthors.insert(a.first);
    }

    for (auto &a: uniqAuthors) {
        set<string> books;
        for (auto pos = authors.equal_range(a); pos.first != pos.second; ++pos.first) {
            books.insert(pos.first->second);
        }
        for (const string &b: books) {
            cout << a << '-' << b << endl;  
        }
    }
	return 0;
}


