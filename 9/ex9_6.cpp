#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;

int main() {
list<int> list1;
list<int>::iterator iter1 = list1.begin(),iter2 = list1.end(); 
while (iter1 != iter2) {
    cout << 'aa' << endl;
}
}
