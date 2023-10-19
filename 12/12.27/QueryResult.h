#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::istream;
using std::ostream;
#include <fstream>
using std::ifstream;
#include <map>
using std::map;
#include <set>
using std::set;
#include <memory>
using std::shared_ptr;

class QueryResult
{
    friend ostream &print(ostream &os, const QueryResult &qr);

public:
    typedef std::vector<string>::size_type line_no_type;
    explicit QueryResult(const string &wd) : word(wd), total(0), lineNumers(), lineText(){};
    explicit QueryResult(const string &wd, line_no_type tt, shared_ptr<const set<line_no_type>> lns, shared_ptr<const vector<string>> lt) : word(wd), total(tt), lineNumers(lns), lineText(lt){};

private:
    string word;
    line_no_type total;
    shared_ptr<const set<line_no_type>> lineNumers;
    shared_ptr<const vector<string>> lineText;
};

ostream &print(ostream &os, const QueryResult &qr);

#endif