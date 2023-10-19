#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

string s[10] = {"aa", "bb"};

string (&fooRef())[10]
{
    return s;
}

string (*fooPtr())[10]
{
    return &s;
}

decltype(s) &fooDclRef() {
    return s;
}

using string_10 = string [10];

string_10 &fooTypeDef() {
    return s;
}

auto fooArrow() -> string (&) [10] {
    return s;
}

int main()
{
    string (&ss)[10] = fooRef();
    for (int i = 0; i < 2; i++)
    {
        cout << ss[i] << endl;
    }
    cout << endl;

    string (*p)[10] = fooPtr();
    for (int i = 0; i < 2; i++)
    {
        cout << (*p)[i] << endl;
    }
    cout << endl;


    string (&ssd)[10] = fooDclRef();
    for (int i = 0; i < 2; i++)
    {
        cout << ssd[i] << endl;
    }
    cout << endl;

    string (&sst)[10] = fooTypeDef();
    for (int i = 0; i < 2; i++)
    {
        cout << sst[i] << endl;
    }
    cout << endl;

    string (&ssa)[10] = fooArrow();
    for (int i = 0; i < 2; i++)
    {
        cout << ssa[i] << endl;
    }
    cout << endl;
}