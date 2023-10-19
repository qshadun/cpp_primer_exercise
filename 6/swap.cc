
#include <iostream>
using std::cout; using std::cin; using std::endl;

void swap(int &p, int &q) {
    int tmp = p;
    p = q;
    q = tmp;
}
 
 void swapP(int *p, int * q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
 }

int main() {
    unsigned int n;
    int x , y;
    x = 10;
    y = 20;
    cout << "x=" << x << ", y=" << y <<endl; 
    swap(x, y);
    cout << "x=" << x << ", y=" << y <<endl; 
     
    swapP(&x, &y);
    cout << "x=" << x << ", y=" << y <<endl;
}
