#include <vector>
#include <iostream>
using namespace std;

template <typename T>
size_t count(vector<T> &vec, const T &val) {
    size_t cnt = 0;
    for (auto v: vec) {
        if (v == val) {
            ++cnt;
        }
    }
    return cnt;
}

template<>
size_t count(vector<const char*> &vec,  const char* const &val) {
    size_t cnt = 0;
    for (auto v: vec) {
        if (strcmp(v, val)) {
            ++cnt;
        }
    }
    return cnt;
}
int main() {
    vector<int> vi{1, 2, 3, 4, 3, 5};
    cout << count(vi, 3) << endl;

    vector<string> vs;
    string s("aa");
    vs.push_back(s);
    vs.push_back("bb");
    vs.push_back(s);
    cout << count(vs, s) << endl;

    // for ex16_64
    vector<const char*> vcc = {"aa", "bb", "aa", "cc"};
    const char* const cs = "aa";
    cout << count(vcc, cs) << endl;
}