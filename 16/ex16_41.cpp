#include <iostream>
#include <type_traits>

template <typename T>
auto sum(T a, T b) -> typename std::make_unsigned<T>::type {
    return a + b;
}

int main() {
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum(INT_MAX, INT_MAX) << std::endl;
}