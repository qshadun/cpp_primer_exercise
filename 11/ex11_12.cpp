
#include <unordered_map>
using std::unordered_map;

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
using familytype = unordered_map<string, vector<string> >;

#include <utility>
using std::pair;

// unordered_map version of the word count program
int main() 
{
	string s;
    int i;
    vector<pair<string, int>> vp;
    while (cin >> s >> i) {
        
        // vp.push_back({s, i});
        // vp.push_back(pair<string, int>(s, i));
        vp.push_back(make_pair(s, i));
    }

    for (auto p: vp) {
        cout << p.first << " " << p.second << endl;
    }
	return 0;
}


