#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

int main() {
    unsigned int cnt, maxCnt;
    string prev, curr;
    while (cin >> curr) {
        if (curr == prev) {
            ++ cnt;
        } else {
            cnt = 1;
        }
        prev = curr;
        if (cnt > maxCnt) {
            maxCnt = cnt;
        }
    }
    if(maxCnt > 1) {
        cout << "max repeat count is " << maxCnt << endl;
    } else {
        cout << "no repeat words" << endl;
    }

}