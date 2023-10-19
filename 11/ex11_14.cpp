
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

#include <utility>
using std::pair;

using familytype = unordered_map<string, vector<pair<string, string>> >;

void addFamily(familytype &family, const string & name) {
    auto ret = family.insert(make_pair(name, vector<pair<string, string>>()));
    if (! ret.second) {
        cerr << "Error: family " << name << " already exists" << endl;;
    }
}

void addChild(familytype &family, const string & familyName, const string &name, const string &birthday) {
    auto it = family.find(familyName);
    if (it != family.end()) {
        (*it).second.push_back({name, birthday});
    } else {
        cerr << "Error: family " << familyName << " does not exist." << endl;
    }
}

// unordered_map version of the word count program
int main() 
{
	familytype family;
    addFamily(family, "Zhang");
    addFamily(family, "Wang");
    addFamily(family, "Zhang"); // error

    addChild(family, "Zhang", "San", "2015-01-24");
    addChild(family, "Zhang", "Si", "2016-01-24");
    addChild(family, "Zhang", "Wu", "2017-01-24");
    addChild(family, "Wang", "Liu", "2012-08-01");
    addChild(family, "Wang", "Qi", "2013-08-01");
    addChild(family, "Tian", "San", "2012-08-01");

    for (const auto &f: family) {
        for (const auto &c: f.second) {
            cout << f.first << " " << c.first << " " << c.second << endl;
        }
    }
	return 0;
}


