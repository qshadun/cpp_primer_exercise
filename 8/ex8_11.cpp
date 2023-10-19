#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
#include <sstream>
#include <fstream>

#include <string>
using std::string;

#include <vector>
using std::vector;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

std::ostream& print(std::ostream& os, const PersonInfo& info) {
    os << info.name << '[';
    int count = 0;
    for (string phone: info.phones) {
        if (count) {
            cout << ',';
        }
        ++count;
        os << phone;
        
    }
    os << ']' << endl;
    return os;
}

int main(int argc, char *argv[])
{
    string line, word;
    vector<PersonInfo> people;
    std::istringstream record;
    string filename = "data/sstream";
    std::ifstream in(filename);
    while (getline(in, line)) {
        record.clear();
        record.str(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for (auto p: people) {
        print(cout, p);
    }
    return 0;
}