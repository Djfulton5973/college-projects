#include <iostream>

template<typename Cal>

Cal Calculator(Cal x, Cal y, char num) {

    switch (num) {
        case 'a':
            std::cout << "\nAddition: ";
            return x + y;
        case 's':
            std::cout << "\nSubtraction: ";
            return x - y;
        case 'm':
            std::cout << "\nMultiplication: ";
            return x * y;
        case 'd':
            std::cout << "\nDivision: ";
            return x / y;
        default:
            std::cout << "\nInvalid input.";
            return 0;
    }

}

int main() {

    std::cout << Calculator(5,6,'a');
    std::cout << Calculator(12,6,'d');
    std::cout << Calculator(6,3,'m');
    std::cout << Calculator(2,1,'s');

    return 0;
}
