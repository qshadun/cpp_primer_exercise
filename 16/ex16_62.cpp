#include "Sales_data.h"
#include <unordered_set>
using namespace std;

int main() {
    
    unordered_multiset<Sales_data> ums;
    ums.emplace("aaa", 1, 5.0);
    ums.emplace("aaa", 1, 5.0);
    ums.emplace("bbb", 1, 10.0);
    for (auto it = ums.begin(); it != ums.end(); ++it) {
        print(cout, *it);
        cout << ", hashcode=" << hash<Sales_data>()(*it); 
        cout << endl;
        
    }
}