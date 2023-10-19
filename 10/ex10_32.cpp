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
#include <numeric>

#include <sstream>
using std::istringstream;

#include <functional>
using std::bind;
using namespace std::placeholders;

#include <list>
using std::list;

#include <iterator>
using std::istream_iterator;
using std::ostream_iterator;

#include <fstream>
using std::ifstream;

#include "Sales_item.h"

bool compareIsbn2(const Sales_item &lhs, const Sales_item &rhs)
{
  return lhs.isbn() < rhs.isbn();
}

int main()
{
  ifstream ifs("data/10.32.in");
  istream_iterator<Sales_item> iter(ifs);
  istream_iterator<Sales_item> eod;
  vector<Sales_item> vs(iter, eod);
  std::sort(vs.begin(), vs.end(), compareIsbn2);
  
  ostream_iterator<Sales_item> out(cout, "\n");
  auto bg = vs.begin();
  while(bg != vs.end()) {
    auto ed = std::find_if(bg, vs.end(), [bg](const Sales_item & si) {return si.isbn() != bg->isbn();});
    out = std::accumulate(bg, ed, Sales_item(bg->isbn()));
    bg = ed;
  }
  return 0;
}