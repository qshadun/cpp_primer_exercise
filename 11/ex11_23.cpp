
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

void addFamily(familytype &family, const string & name) {
    family.insert(make_pair(name, vector<string>()));

}

void addChild(familytype &family, const string & familyName, const string &name) {
    auto it = family.find(familyName);
    if (it != family.end()) {
        (*it).second.push_back(name);
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
    addFamily(family, "Zhang"); 

    addChild(family, "Zhang", "San");
    addChild(family, "Zhang", "Si");
    addChild(family, "Zhang", "Wu");
    addChild(family, "Wang", "Liu");
    addChild(family, "Wang", "Qi");
    addChild(family, "Tian", "San");

    for (const auto &pair: family) {
        for (const auto &name: pair.second) {
            cout << pair.first << " " << name << endl;
        }
    }
	return 0;
}


