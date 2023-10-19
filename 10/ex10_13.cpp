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

ostream & print(ostream &os, const vector<string> &vi) {
  for (auto num: vi) {
    os << num << ' ';
  }
  os << endl;
  return os;
}

bool isLong(const string & s) {
  return s.size() >= 5;
}
int main()
{
  vector<string> vs = {"life", "power", "what", "can", "I", "do", "magic", "what", "read", "red", "power", "Chinese"};
  print(cout, vs);
  auto iter = std::partition(vs.begin(), vs.end(), isLong);
  print(cout, vs);
  for (auto it = vs.begin(); it != iter; ++it) {
    cout << *it << ' ';
  }
  cout << endl;
  return 0;
}