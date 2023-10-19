#include <string>
using std::string;

#include <iostream>
using std::cout; using std::cin; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::count;

#include <sstream>
using std::istringstream;

int main() {
    string line;
    cout << "please input numbers: " << endl;
    getline(cin, line);
    istringstream iss(line);
    int num;
    vector<int> vi;
    while (iss >> num) {
        vi.push_back(num);
    }

    int target;
    cout << "please input a target: ";
    cin >> target;
    int cnt = count(vi.begin(), vi.end(), target);
    cout << "there are " << cnt << " times of " << target << endl;

}