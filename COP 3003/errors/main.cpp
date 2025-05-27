#include <iostream>

int main() {

    int x;
    int y;

    std::cout << "Enter two numbers for x and y:\n";
    std::cin >> x >> y;

    try {

        if (x < 0 && y < 0)
            throw 'n';
        else if ((x < 0 && y >= 0) || (x >= 0 && y < 0))
            throw -101;

    }
    catch (char n) {
        std::cout << "Negative numbers shouldn't be used." << std::endl;
        std::cout << "Error: " << n;
    }
    catch (int negative) {
        std::cout << "One of your numbers shouldn't be negative shouldn't be used." << std::endl;
        std::cout << "Error: " << negative;
    }

    return 0;
}