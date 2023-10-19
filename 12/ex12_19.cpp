#include <memory>
using std::make_shared;
using std::shared_ptr; using std::weak_ptr;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <exception>
using std::out_of_range;
#include <fstream>
using std::ifstream;

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
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
    StrBlobPtr begin();
    StrBlobPtr end();

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

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) {};
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {};
    bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
    string& deref() const;
    StrBlobPtr& incr(); 
private:
    size_t curr;
    weak_ptr<vector<string>> wptr;
    shared_ptr<vector<string>> check(size_t, const string &) const;
};

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw out_of_range(msg);
    }
    return ret;
}

string& StrBlobPtr::deref() const {
    auto p = check(curr, "derefrence past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, this->size());
}

int main()
{   
    StrBlob sb;
    string s;
    ifstream ifs("data/storyDataFile");
    while (getline(ifs, s)) {
        sb.push_back(s);
    }
    for (StrBlobPtr pbeg(sb.begin()), pend(sb.end()); pbeg!=pend; pbeg.incr()) {
        cout << pbeg.deref() << endl;
    }
}