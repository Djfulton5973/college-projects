#include <iostream>

int main() {

    int row, a, b, c;

    std::cout << "Enter the number of rows:";
    std::cin >> row;

    // the loop for the Fibonacci Triangle
    for (int i = 1; i <= row; i++) {

        a = 0;
        b = 1;

        // the first number in the row
        std::cout << b << "\t";

        for (int j = 1; j < i; j++) { // the numbers after the first

            c = a + b;
            std::cout << c << "\t";
            a = b;
            b = c;

        }

        std::cout << "\n";

    }

    return 0;
}