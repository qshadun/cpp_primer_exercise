#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main() {
    vector<int> ivec(10, 0);
    vector<int>::size_type cnt = ivec.size();
    for(vector<int>::size_type ix = 0;
        ix != ivec.size(); ++ix, --cnt) 
        ivec[ix] = cnt;
    for (int i = 0; i < ivec.size(); i ++) {
        cout << ivec[i] << ' ';
    }
    cout << endl;
    return 0;
}