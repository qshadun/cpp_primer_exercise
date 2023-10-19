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

#include <sstream>
using std::istringstream;

#include <functional>
using namespace std::placeholders;
using std::bind;

bool bigger(int num, const string& s) {
  return num > s.size();
}

int main()
{
  vector<int> vi = {1,2,3,4,5,6,7,8,9, 10, 11};
  string s = "Wonderful";
  auto iter = std::find_if(vi.begin(), vi.end(), bind(bigger, _1, s));
  cout << *iter << endl;
  return 0;
}