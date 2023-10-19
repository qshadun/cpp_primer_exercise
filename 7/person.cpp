#include "Person.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

int main()
{
    Person p;
    read(cin, p);
    print(cout, p) << endl;

    print(cout, Person("aa")) << endl;
    print(cout, Person("aa", "bb")) << endl;

    print(cout, Person(cin)) << endl;
}