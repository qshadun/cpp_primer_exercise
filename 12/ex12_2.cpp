#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <exception>
using std::out_of_range;

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<string> il);
    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }

    void push_back(const string &t);

    void popback();
    string &front();
    string &back();
    const string &back() const;
    const string &front() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

inline StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}

inline StrBlob::StrBlob(std::initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

void StrBlob::push_back(const string &t)
{
    data->push_back(t);
}

void StrBlob::popback()
{
    check(0, "popback on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

int main()
{   
    StrBlob sb;
    sb.push_back("aaa");
    sb.push_back("bbb");
    cout << sb.front() << endl;
    cout << sb.back() << endl;
    return 0;
}