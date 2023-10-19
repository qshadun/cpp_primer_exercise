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
  int a = 10;
  auto sum = [a](const int &i) {return i + a;};
  cout << sum(3) << endl;
}