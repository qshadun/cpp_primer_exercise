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
  vector<int> vi{0, 1,2,3,4,5, 6, 7, 8, 9};
  list<int> li;
  for (auto it = vi.rbegin() + 2; it != vi.rend() - 3; ++it) {
    li.push_back(*it);
  }
  ostream_iterator<int> out(cout, " ");
  std::copy(li.cbegin(), li.cend(), out);
  cout << endl;
  return 0;
}