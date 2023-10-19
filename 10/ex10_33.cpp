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
  ifstream ifs("data/10.33.in");
  istream_iterator<int> iter(ifs);
  istream_iterator<int> eod;
  vector<int> vi(iter, eod);
  // std::sort(vi.begin(), vi.end());
  // std::copy(str_it, str_eof, std::back_inserter(vs));
  auto evenStart = std::stable_partition(vi.begin(), vi.end(), [](const int i) {return i % 2;});

  ofstream ofsOdd("data/odd"), ofsEven("data/even");
  ostream_iterator<int> outOdd(ofsOdd, " "), outEven(ofsEven, "\n");
  std::copy(vi.begin(), evenStart, outOdd);
  std::copy(evenStart, vi.end(), outEven);
  
  return 0;
}