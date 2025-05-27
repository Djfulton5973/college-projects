#include <iostream>

void isOdd(int);
void isEven(int);

int main() {

    int x;
    std::cout << "Enter an number:";
    std::cin >> x;

    isOdd(x);
    isEven(x);

    return 0;
}

void isOdd(int a) {

    if (a % 3 == 0 || a % 5 == 0 || a % 7 == 0)
        std::cout << "It is an odd number,";
    else if (a == 1)
        std::cout << "It is an odd number,";
    else
        std::cout << "It is not an odd number,";

}

void isEven(int b) {

    if (b % 2 == 0)
        std::cout << " but an even number." << std::endl;
    else
        std::cout << " not an even number." << std::endl;

}