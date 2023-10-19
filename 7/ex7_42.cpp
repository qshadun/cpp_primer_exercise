#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Person;

ostream & print(ostream &os, Person p);

class Person
{
friend ostream & print(ostream &os, Person p);
public:
    Person(const string &nm, const string &addr) : name(nm), address(addr) {}
    Person(): Person("", "") {}
private:
    string name;
    string address;
};

ostream & print(ostream &os, Person p) {
    os << p.name << " " << p.address;
    return os;
}

int main() {
    Person p;
    print(cout, p) << endl;
}

