#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::istream;
#include <fstream>
using std::ifstream;
#include <map>
using std::map;
#include <set>
using std::set;
#include <memory>
using std::shared_ptr;

class QueryResult;

class TextQuery {
public:
    typedef vector<string>::size_type line_no_type;
    explicit TextQuery(istream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> text;
    map<string, shared_ptr<set<line_no_type>>> lines;
};

#endif