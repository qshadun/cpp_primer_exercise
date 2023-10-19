#ifndef PERSON
#define PERSON

#include <string>
using std::string;

#include <iostream>

class Person;
std::istream &read(std::istream &is, Person &p);

class Person
{
    friend std::istream &read(std::istream &is, Person &p);
    friend std::ostream &print(std::ostream &os, const Person &p);
    public:
        Person() = default;
        Person(const string &name) : name(name) {}
        Person(const string &name, const string address) : name(name), address(address) {}
        Person(std::istream &is) { read(is, *this); } 

        string getName() const { return name; }
        string getAddress() const { return address; }
    private:
        string name;
        string address;
};

std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.address;
    return os;
}

#endif