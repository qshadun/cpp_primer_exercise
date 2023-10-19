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


int main()
{
  ifstream ifs("data/accum");
  istream_iterator<string> str_it(ifs);
  istream_iterator<string> str_eof;
  vector<string> vs(str_it, str_eof);
  // std::copy(str_it, str_eof, std::back_inserter(vs));
  ostream_iterator<string> out(cout, " ");
  std::copy(vs.begin(), vs.end(), out);
  cout << endl;
  return 0;
}