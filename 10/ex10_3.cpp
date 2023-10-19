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

#include <list>
using std::list;

#include <numeric>
using std::accumulate;

int main() {
    vector<int> vi = {1, 2, 3, 4, 5};
    cout << accumulate(vi.begin(), vi.end(), 0) << endl;

    vector<double> vd = {1.0, 2.2, 3.4};
    cout << accumulate(vd.begin(), vd.end(), 0.) << endl;

}