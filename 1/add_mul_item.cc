#include <iostream>
#include "Sales_item.h"

int main() 
{
    Sales_item item1, item2;

    std::cin >> item1;   //read a pair of transactions
    while (std::cin >> item2) {
        item1 += item2;
    }

    std::cout << item1 << std::endl; //print their sum

    return 0;
}