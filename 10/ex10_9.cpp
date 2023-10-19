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

ostream & print(ostream &os, const vector<int> &vi) {
  for (auto num: vi) {
    os << num << ' ';
  }
  os << endl;
  return os;
}

int main()
{
  vector<int> vi = {1,2,2,1,3,5,3,4,5,3};
  print(cout, vi);
  std::sort(vi.begin(), vi.end());
  print(cout, vi);
  auto iter = std::unique(vi.begin(), vi.end());
  print(cout, vi);
  vi.erase(iter, vi.end());
  print(cout, vi);
  return 0;
}