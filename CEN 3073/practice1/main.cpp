#include <iostream>

class MathOperations {
public:
    int additionOp();
    int subtractionOp();
    int multiplyOp();
    int divideOp();
private:
    int i;
    int j;
};

int MathOperations::additionOp() {

    std::cout << "Enter the first integer: ";
    std::cin >> i;

    std::cout << "\nEnter the second integer: ";
    std::cin >> j;

    int h = i + j;

    return h;
};

int MathOperations::subtractionOp() {

    std::cout << "Enter the first integer: ";
    std::cin >> i;

    std::cout << "\nEnter the second integer: ";
    std::cin >> j;

    int h = i - j;

    return h;
};

int MathOperations::multiplyOp() {

    std::cout << "Enter the first integer: ";
    std::cin >> i;

    std::cout << "\nEnter the second integer: ";
    std::cin >> j;

    int h = i * j;

    return h;
};

int MathOperations::divideOp() {

    std::cout << "Enter the first integer: ";
    std::cin >> i;

    std::cout << "\nEnter the second integer: ";
    std::cin >> j;

    int h = i / j;

    return h;
};

int main() {

    std::cout << "Choose the following operations to use two integers:"
                 "\n 1. Addition"
                 "\n 2. Subtraction"
                 "\n 3. Multiplication"
                 "\n 4. Division\n";
    
    int num;
    std::cin >> num;

    switch (num) {
        case 1:
            MathOperations::additionOp();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }

    return 0;
}
