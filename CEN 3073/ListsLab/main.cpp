#include <iostream>
#include "DynamicFunctions.cpp"

int main() {

    DynamicList list = DynamicList();

    // display the list before the function
    std::cout << "The list before: ";
    list.print();

    // outputs the value it finds
    std::cout << "\nThe value: ";
    std::cout << list.findOrInsert(6)->info << "\n" << std::endl;
    std::cout << list.findOrInsert(9)->info << "\n" << std::endl;

    // display the list after the function
    std::cout << "The list after: ";
    list.print();

    return 0;
}
