#include <iostream>
using std::cout; using std::cin; using std::endl;
using std::getline;
#include <sstream>
#include <fstream>

#include <string>
using std::string;

#include <vector>
using std::vector;

std::istream& read(std::istream& is) {
    string s;
    while (is >> s) {
        cout << s << endl;
    }
    cout << endl;
    is.clear();
    return is;
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        cout << "please speicify input file" << endl;
    }
    std::ifstream in(argv[1]);
    string line;
    vector<string> vs;
    while (getline(in, line)) {
        vs.push_back(line);
    }
    for (string ln : vs) {
        std::istringstream iss(ln);
        read(iss);
    }
    
    return 0;
}