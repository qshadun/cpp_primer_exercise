#include <iostream>

int main() {
    int i  = 42;
    const int &r1 = i;
    std::cout << "i: " << i << " r1: " << r1 << std::endl;
    i = 33;
    std::cout << "i: " << i << " r1: " << r1 << std::endl;

    double dval = 3.14;
    const int &ri = dval;
    std::cout << "dval: " << dval << " ri: " << ri << std::endl;
    dval = 6.28;
    std::cout << "dval: " << dval << " ri: " << ri << std::endl;

    const double pi = 3.14; // pi is const; its value may not be changed 
    // double *ptr= &pi; // error:ptrisaplainpointer 
    const double *cptr= &pi;// ok:cptr may pointtoadoublethatisconst 
    //*cptr = 42; // error: cannot assign to *cptr
    int *p = 0;
    const int i = 0;

    return 0;
}