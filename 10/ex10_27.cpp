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
using std::bind;
using namespace std::placeholders;

#include <list>
using std::list;


int main()
{
  vector<int> vi{1, 1, 2, 2, 3, 4, 5, 5};
  list<int> li;
  std::unique_copy(vi.begin(), vi.end(), std::back_inserter(li));
  for (int i: li) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}