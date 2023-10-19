#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;


void combine(string &name, const string& prefix, const string &suffix) {
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" " + suffix) ;
}

int main()
{
    string s("Ray");
    combine(s, "Mr.", "Jr.");
    cout << s << endl;

}
