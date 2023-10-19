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

int main()
{
  int num = 5;
  auto lmd = [num]() mutable -> bool {
    if (num > 0) {
       -- num;
    }
    return num == 0;
  };
  for (int i = 0; i < 5; ++i) {
    cout << lmd() << endl;
  }
  cout << num << endl;
  std::cout << typeid(lmd()).name() << std::endl;
}