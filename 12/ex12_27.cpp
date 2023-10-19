#include <memory>
using std::make_shared;
using std::shared_ptr; using std::weak_ptr;
using std::allocator;
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <exception>
using std::out_of_range;
#include <fstream>
using std::ifstream;

#include "12.27/QueryResult.h"
#include "12.27/TextQuery.h"

int main() {
    ifstream ifs("data/storyDataFile");
    TextQuery tq(ifs);
    while (true) {
        cout << "Enter word to look for, or 'q' to exit:";
        string s;
        if (! (cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}