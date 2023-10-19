#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <vector>
using std::vector;





int main()
{
  auto sum = [](const int &i1, const int &i2) {return i1 + i2;};
  cout << sum(2, 3) << endl;
}