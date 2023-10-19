
#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <set>
using std::multiset; using std::set;

#include <map>
using std::map; using std::multimap;

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

#include <utility>
using std::pair;

#include <algorithm>
using std::copy;

#include <iterator>
using std::inserter; using std::back_inserter;


int main() 
{   
    map<string, int> wordCount;
    string word;
    while (cin >> word) {
        auto ret = wordCount.insert({word, 1});
        if (!ret.second) {
            ++ ret.first->second;
        }
    }
    for (auto &entry: wordCount) {
        cout << entry.first << ' ' << entry.second << endl;
    }
	return 0;
}


