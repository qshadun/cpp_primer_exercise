#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::endl; using std::cin;

typedef int (*OP) (int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("divide by zero");
    }
    return a / b;
}

int main() {
    OP fp = add;
    vector<OP> fps;
    fps.push_back(add);
    fps.push_back(subtract);
    fps.push_back(multiply);
    fps.push_back(divide);
    int a = 4, b = 2;
    for (int i = 0; i != 4; ++i) {
        cout << fps[i] (a, b) << endl;
    }
}