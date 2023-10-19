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




void elimDups(vector<string> & vs) {
  std::sort(vs.begin(), vs.end());
  auto iter = std::unique(vs.begin(), vs.end());
  vs.erase(iter, vs.end());
  std::stable_sort(vs.begin(), vs.end(), [](const string &s1, const string &s2) {
    return s1.size() < s2.size();
  });
}
string make_plrual(const string& s, const int count) {
  if (count > 1) {
    return s + 's';
  } else {
    return s;
  }
}

void biggie(vector<string> &vs, vector<string>::size_type sz) {
  elimDups(vs);
  int count = std::count_if(vs.begin(), vs.end(), [sz](const string& s) {return s.size() >= sz;});
  cout << "there are " << count << " " << make_plrual("word", count) << " equal or longer than " << sz << " letters." << endl;
}

int main()
{
  string line = "I have never been so frightened.";
  vector<string> vs;
  string s;
  istringstream iss(line);
  while(iss >> s) {
    vs.push_back(s);
  }
  biggie(vs, 3);
}