#include <iostream>
#include <memory>
#include <string>

class DebugDelete{
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) {}

    template <typename T> void operator()(T *p) const {
        os << "delete pointer " << typeid(p).name() << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

int main() {
    int *ip = new int(5);
    double *dp = new double(5.5);
    DebugDelete d;
    d(ip);
    DebugDelete()(dp);

    std::unique_ptr<int, DebugDelete> uip(new int(10), DebugDelete());
    std::unique_ptr<std::string, DebugDelete> usp(new std::string("aaaa"), DebugDelete());
}

