#include <vector>
#include <iostream>
#include <string>

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) {
    // process the range
    return *beg; // return a copy of an element from the range
}

int main() {
    std::vector<int> vi{1, 2};
    fcn3(vi.begin(), vi.end());

    std::vector<std::string> vs;
    // fcn3(vs.begin(), vs.end()); // error: no matching function for call to 'fcn3'
}