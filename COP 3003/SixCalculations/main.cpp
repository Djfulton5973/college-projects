#include <iostream>

void mathOperations(int,int,int);

int main() {

    int x, y;

    std::cout << "Enter a number for x:";
    std::cin >> x;

    std::cout << "Enter a number for y:";
    std::cin >> y;

    int userInput;

    std::cout << "You have the following options:" << std::endl;
    std::cout << "1) Add" << std::endl;
    std::cout << "2) Subtract" << std::endl;
    std::cout << "3) Multiply" << std::endl;
    std::cout << "4) Divide" << std::endl;
    std::cout << "5) Modulus" << std::endl;
    std::cout << "6) Increment (for only x)" << std::endl;
    std::cout << "7) Decrement (for only x)" << std::endl;

    mathOperations(x,y,userInput);

    return 0;
}

void mathOperations(int n1,int n2, int user) {

    std::cout << "\nEnter a number:";
    std::cin >> user;

    switch (user) {

        case 1: // addition
            std::cout << "x + y = " << n1 + n2;
            break;
        case 2: // subtraction
            std::cout << "x - y = " << n1 - n2;
            break;
        case 3: // multiplication
            std::cout << "x * y = " << n1 * n2;
            break;
        case 4: // division
            std::cout << "x / y = " << n1 / n2;
            break;
        case 5: // modulus
            std::cout << "x % y = " << n1 % n2;
            break;
        case 6: // increment
            std::cout << "++x = " << n1;
            break;
        case 7: // decrement
            std::cout << "--x = " << --n1;
            break;
        default:
            std::cout << "Not a valid input.";
            // recursive call to prompt for a new number
            mathOperations(n1,n2,user);
    }

}