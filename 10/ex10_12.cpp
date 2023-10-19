#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;

#include <algorithm>
using std::count;

#include <sstream>
using std::istringstream;

#include <list>
using std::list;

#include <numeric>
using std::fill_n;

#include "../7/Sales_data.h"

int main()
{
  vector<Sales_data> vs;
  Sales_data sd;
  while (read(cin, sd)) {
    vs.push_back(sd);
  }
  std::sort(vs.begin(), vs.end(), compareIsbn);
  for (auto it = vs.begin(); it != vs.end(); ++it) {
    print(cout, *it);
    cout << endl;
  }
  return 0;
}