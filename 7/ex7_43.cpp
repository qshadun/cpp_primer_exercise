#include <vector>
using std::vector;


class NoDefault
{
public:
    NoDefault(int a) {}
};

class C
{
public:
    C(): noDefault(0) {}

private:
    NoDefault noDefault;
};

int main() {
    vector<C> vec(10);
    return 0;
}