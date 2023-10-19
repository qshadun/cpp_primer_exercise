#include "TextQuery.h"
#include "QueryResult.h"
#include <sstream>
using std::istringstream;
using std::make_shared;

TextQuery::TextQuery(istream& in): text(make_shared<vector<string>>()) {
    line_no_type ln = 0;
    string line;
    while (getline(in, line)) {
        text->push_back(line);
        istringstream iss(line);
        string word;
        while(iss >> word) {
            if (lines.find(word) == lines.end()) {
                lines[word] = make_shared<set<line_no_type>>();
            }
            lines[word]->insert(ln);
        }
        ++ln;
    }
}


QueryResult TextQuery::query(const string& word) const{
    auto it = lines.find(word);
    if (it == lines.end()) {
        return QueryResult(word);
    }
    line_no_type total = 0;
    for (const auto &ln: *(it -> second)) {
        istringstream iss((*text)[ln]);
        string wd;
        while(iss >> wd) {
            if (wd == word) {
                ++total;
            }
        }
    }
    return QueryResult(word, total, it->second, text); 
}
