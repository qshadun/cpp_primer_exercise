#include <tuple>

#include <vector>
#include <utility>
#include <string>
using namespace std;


int main() {
    tuple<int, int, int> triple(10, 20, 30);
    tuple<string, vector<string>, pair<string, int>> t2("abc", {"aa", "bb", "cc"}, {"aaa", 10});
    
}