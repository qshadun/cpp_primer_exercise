#include <string>
#include <iostream>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &ori)
      : ps(new std::string(*ori.ps)), i(ori.i) {}

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }
  HasPtr & operator=(const HasPtr &);
  ~HasPtr () {}

private:
  std::string *ps;
  int i;
};

HasPtr & HasPtr::operator=(const HasPtr & rhs) {
  std::string * nps = new std::string(*rhs.ps);
  delete ps;
  ps = nps;
  i = rhs.i;
  return *this;
}

int main() {
  HasPtr hp1 = std::string("World");
  HasPtr hp2 = hp1;
  hp1.set("Hello");

  std::cout << hp1.get() << " " << hp2.get() << std::endl;

  return 0;
}
