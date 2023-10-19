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
  vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> vi_back;
  std::copy(vi.begin(), vi.end(), std::back_inserter(vi_back));
  cout << "back insert: ";
  for (int i: vi_back) {
    cout << i << ' ';
  }
  cout << endl;

  list<int> li_front;
  std::copy(vi.begin(), vi.end(), std::front_inserter(li_front));
  cout << "front insert: ";
  for (int i: li_front) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> vi_inserter;
  std::copy(vi.begin(), vi.end(), std::inserter(vi_inserter, vi_inserter.begin()));
  cout << "inserter insert: ";
  for (int i: vi_inserter) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}