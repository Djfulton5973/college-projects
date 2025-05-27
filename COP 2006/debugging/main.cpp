#include <iostream>

void printResult(int z);
double getUserInput();
double fSub(double dividend, double divisor);

int main()
{

    std::cout << "Enter a dividend and divisor that";
    std::cout << " will equally divide to zero" << std::endl;

    double x = getUserInput();
    double y = getUserInput();

    std::cout << x << " / " << y << std::endl;

    int n = 0;
    while (x > 0) {
        std::cout << x << std::endl;
        x = fSub(x, y);
        n++;
    }
    n--;

    printResult(n);

    char wait;
    std::cin >> wait;

    return 0;
}

void printResult(int z)
{
    std::cout << "The answer is: " << z << '\n';
}

double getUserInput()
{
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;
    return x;
}

double fSub(double dividend, double divisor) {
    return dividend - divisor;
}