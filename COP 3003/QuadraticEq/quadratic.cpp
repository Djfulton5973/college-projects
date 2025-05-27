/**********************************************************
 * file: quadratic.cpp
 * author: Darren Fulton
 * class: COP 3003 Fall 2022
 * purpose: give 2 solutions from the quadratic equations
 *********************************************************/

#include <iostream>
#include <cmath>

int main() {

    double a, b, c, x1, x2;

    std::cout << "Enter a number for a:";
    std::cin >> a;

    std::cout << "Enter a number for b:";
    std::cin >> b;

    std::cout << "Enter a number for c:";
    std::cin >> c;

    //the quadratic equation with the addition
    x1 = (-b + sqrt(pow(b,2) - 4 * a * c))/ (2 * a);

    //the quadratic equation with the subtraction
    x2 = (-b - sqrt(pow(b,2) - 4 * a * c))/ (2 * a);

    std::cout << "\nStandard form: (" << a << ")x^2 + (" << b << ")x + (";
    std::cout << c << ")" <<std::endl;

    std::cout << "Solution 1 (+): " << x1 << std::endl;

    std::cout << "Solution 2 (-): " << x2 << std::endl;

    return 0;
}
