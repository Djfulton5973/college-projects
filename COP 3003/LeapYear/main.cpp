#include <iostream>

int main() {

    int year = 1700;

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        std::cout << "It is a leap year." << std::endl;
    else
        std::cout << "It is not a leap year." << std::endl;

    return 0;
}
