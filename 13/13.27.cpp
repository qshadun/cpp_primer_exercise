#include <string>
#include <iostream>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new int(1)) {}
  HasPtr(const HasPtr &ori)
      : ps(ori.ps), i(ori.i), use(ori.use) {++*use;}

  const std::string &get() const { return *ps; }
  void set(const std::string &s) { *ps = s; }
  HasPtr & operator=(const HasPtr &);
  ~HasPtr ();

private:
  std::string *ps;
  int i;
  int * use;
};

HasPtr & HasPtr::operator=(const HasPtr & rhs) {
  std::string * nps = new std::string(*rhs.ps);
  ++*rhs.use;
  if (--*use == 0) {
    delete ps;
    delete use;
  }
  use = rhs.use;
  ps = nps;
  i = rhs.i;
  return *this;
}

HasPtr::~HasPtr() {
  if (--*use == 0) {
    delete ps;
    delete use;
  }
}
int main() {
  HasPtr hp1 = std::string("World");
  HasPtr hp2 = hp1;
  hp1.set("Hello");

  std::cout << hp1.get() << " " << hp2.get() << std::endl;

  return 0;
}
