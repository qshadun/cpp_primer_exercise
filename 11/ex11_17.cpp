
#include <unordered_map>
using std::unordered_map;

#include <unordered_set>
using std::unordered_set; using std::unordered_multiset;

#include <set>
using std::multiset; using std::set;
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
    vector<int> v{0,1,2,3,4,5,6,7,8,9};
	multiset<int> c;
    copy(v.begin(), v.end(), inserter(c, c.end()));

    for (auto i : c) {
        cout << i << ' ';
    }
    cout << endl;

    // copy(v.begin(), v.end(), back_inserter(c, c.end()));

    copy(c.begin(), c.end(), inserter(v, v.end()));
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << endl;

    copy(c.begin(), c.end(), back_inserter(v));
    for (auto i: v) {
        cout << i << ' ';
    }
    cout << endl;
	return 0;
}


