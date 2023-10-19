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

bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}
void elimDups(vector<string> & vs) {
  std::sort(vs.begin(), vs.end());
  auto iter = std::unique(vs.begin(), vs.end());
  vs.erase(iter, vs.end());
  std::stable_sort(vs.begin(), vs.end(), isShorter);
}

int main()
{
  vector<string> vs = {"life", "power", "what", "can", "I", "do", "magic", "what", "read", "red", "power"};
  print(cout, vs);
  elimDups(vs);
  print(cout, vs);
  return 0;
}