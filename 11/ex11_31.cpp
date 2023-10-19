
#include <unordered_map>
using std::unordered_map;

#include <map>
using std::map; using std::multimap;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

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

using familytype = multimap<string, vector<string> >;


// unordered_map version of the word count program
int main() 
{
	multimap<string, string> authors{
        {"Brian, Jordan", "A Book"}, 
        {"Benjemin, Bob", "Another Book"},
        {"Brian, Jordan", "A Book 2"}
    };

    auto it = authors.find("Brian, Jordan");
    if (it != authors.end()) {
        cout << it->first << ' ' << it->second << endl;
    } else {
        cout << "Not find" << endl;
    }
    auto count = authors.erase("Brian, Jordan");
    cout << count << endl;

    for (auto &a: authors) {
        cout << a.first << ' ' << a.second << endl;
    }
	return 0;
}


