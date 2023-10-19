#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;


void combine(string &name, const string& prefix, const string &suffix) {
    name.insert(0, prefix + " ");
    name.insert(name.size(), " " + suffix);
}

int main()
{
    string s("Ray");
    combine(s, "Mr.", "Jr.");
    cout << s << endl;

}
