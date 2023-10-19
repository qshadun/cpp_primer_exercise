#include <string>
using std::string;
#include <iostream>
using std::cerr; using std::cout; using std::endl;
#include <fstream>
using std::ifstream;

string ascenders = "bdfhijklt";
string descenders = "gjpqy";
//"abcdefghijklmnopqrstuvwxyz"
string no_ascender_and_descender = "acemnorsuvwxz";

bool has_ascender_or_descender(const string &word) {
  return word.find_first_not_of(no_ascender_and_descender) != string::npos;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "please specify input file";
  }
  
  string longest_word = "";
  string word;
  ifstream ifs(argv[1]);
  while (ifs >> word) {
    if (!has_ascender_or_descender(word)) {
      if (word.size() > longest_word.size()) {
        longest_word = word;
      }
    }
  }
  cout << longest_word << endl;
  return 0;
}