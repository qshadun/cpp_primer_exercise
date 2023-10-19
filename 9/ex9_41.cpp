#include <string>
using std::string;
#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
#include <deque>
using std::deque;
#include <sstream>
using std::istringstream;

#include <forward_list>
using std::forward_list;



int main()
{
    vector<char> vs{'a', 'b', 'c'};
    // char arr[vs.size() + 1];
    // for (int i = 0; i < vs.size(); i++) {
    //     arr[i] = vs[i];
    // }
    // arr[vs.size()] = 0;
    // string s(arr);
    string s(vs.begin(), vs.end());
    cout << s << endl;
}
