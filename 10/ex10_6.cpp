#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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

int main()
{
  vector<int> vi(10);
  fill_n(vi.begin(), 10, 10);
  for (auto num : vi)
  {
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}