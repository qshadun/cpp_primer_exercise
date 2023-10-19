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

ostream & print(ostream &os, const list<int> &li) {
  for (auto num: li) {
    os << num << ' ';
  }
  os << endl;
  return os;
}

int main()
{
  list<int> li = {1,2,2,1,3,5,3,4,5,3};
  print(cout, li);
  li.sort();
  print(cout, li);
  li.unique();
  print(cout, li);
  
  return 0;
}