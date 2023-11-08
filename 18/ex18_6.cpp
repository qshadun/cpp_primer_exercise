#include <iostream>
using namespace std;

class exceptionType {};

void f() {
    try{
        throw new exceptionType();
    } catch (exceptionType *pet) {
        cout << "caught exceptionType *pet" << endl;
        throw;
    }
}

void g() {
    try {
        f();
    } catch (...) {
        exception_ptr eptr = current_exception();
        try {
            rethrow_exception(eptr);
        } catch (exceptionType *e) {
            cout << "caught ...: " << endl;
        }
        
    }
}

typedef int EXCPTYPE;

void h() {
    try {
        EXCPTYPE i = 2;
        throw i;
    } catch (EXCPTYPE) {
        cout << "catch EXCPTYPE" << endl;
    }
}
int main() {
    g();
    h();
}