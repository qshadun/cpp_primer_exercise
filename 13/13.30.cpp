#include <string>
#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &ori)
      : ps(new std::string(*ori.ps)), i(ori.i) {}

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }
  HasPtr & operator=(HasPtr);
  bool operator<(const HasPtr &) const;

  ~HasPtr () { delete ps;}

private:
  std::string *ps;
  int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
  cout << "swap " << *(lhs.ps) << " " << *(rhs.ps) <<endl;
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

HasPtr & HasPtr::operator=(HasPtr rhs) {
  swap(*this, rhs);
  return *this;
}

bool HasPtr::operator<(const HasPtr &rhs) const {
  return *ps  == *(rhs.ps) ? i < rhs.i : *ps  < *(rhs.ps);
}

int main() {
  HasPtr hp1 = std::string("World");
  HasPtr hp2 = hp1;
  hp1.set("Hello");
  HasPtr hp3;
  hp3 = hp1;

  std::cout << hp1.get() << " " << hp2.get() << std::endl;

  vector<HasPtr> vh;
  vh.push_back(HasPtr("bbb"));
  vh.push_back(HasPtr("aaa"));
  sort(vh.begin(), vh.end());
  return 0;
}
