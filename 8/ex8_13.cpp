#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::cerr;
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

bool isValid(const string &num) {
    if (num.size() != 11) {
        return false;
    }
    for (char c: num) {
        if (c < '0' || c > '9') {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    string line, word;
    vector<PersonInfo> people;
    std::istringstream record;
    string filename = "data/8_13.txt";
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
    for (const auto &entry: people) {
        std::ostringstream formatted, badNum;
        for (const auto &phone: entry.phones) {
            if (isValid(phone)) {
                formatted << phone << ' '; 
            } else {
                badNum << phone << ' ';
            }
        }
        if (badNum.str().empty()) {
            cout << entry.name << ' ' << formatted.str() << endl;
        } else {
            cerr << "input error: " << entry.name << " invalid number(s) " << badNum.str() << endl;
        }

    }
    return 0;
}