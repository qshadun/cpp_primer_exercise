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

#include <iterator>
using std::istream_iterator; using std::ostream_iterator;

#include <fstream>
using std::ifstream;
using std::ofstream;


int main()
{
  vector<int> vi{1,2,3,4,5};
  for (auto it = --vi.end(); it + 1 != vi.begin(); --it) {
    cout << *it << ' ';
  }
  cout << endl;
  return 0;
}