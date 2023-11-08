#include <iostream>
using namespace std;

struct Foo {

};

template <typename T>
ostream &print(ostream &os, const T &t)
{
    os << t;
    return os;
}

template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args &...rest)
{
    os << t;
    return print(os, rest...);
}


int main()
{

    print(cout, 1, 1.1, "aaa", 'b', 1);
    Foo bar;
    // print(cout, bar);
}