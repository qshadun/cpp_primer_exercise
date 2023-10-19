#include <string>
using std::string;
#include <iostream>
using std::cout;using std::endl;
#include <fstream>
using std::ifstream;

class BoundString {
public:
    BoundString(int lo, int hi): low(lo), high(hi) {}
    bool operator()(string &);
private:
    int low, high;
};

bool BoundString::operator()(string &s) {
    return s.size() >= low && s.size() <= high;
}
int main(){
    BoundString bs(1, 10);
    ifstream in("data/count-size");
    string s;
    int cnt = 0;
    while (in >> s) {
        if (bs(s)) {
            ++cnt;
        }
    }
    cout << cnt << endl;
}