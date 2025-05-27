#include <iostream>

int main() {

    int x;

    std::cout << "Enter a number:";
    std::cin >> x;

    // starts the table from 1 through 12
    for (int i = 1; i < 13; ++i) {

        std::cout << x << " * " << i << " = " << x * i << std::endl;

    }

    return 0;
}
