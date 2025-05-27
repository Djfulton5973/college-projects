/**********************************************************
 * file: Pythagorean.cpp
 * author: Darren Fulton
 * class: COP 2006 Summer 2022
 * purpose: input two integers and get a solution that's a double
 *********************************************************/

#include <iostream>

#include <cmath>

int main() {

    std::cout << "Calculate distance between 2 points on a triangle \n"
                 "using Pythagorean's equation a^2 + b^2 = c^2." << std::endl;

    int firstInteger = 0;

    //prompt user for the first integer a
    std::cout << "Enter value a:";
    std::cin >> firstInteger;

    int secondInteger = 0;

    //prompt user for the second integer b
    std::cout << "Enter value b:";
    std::cin >> secondInteger;

    //the square root of a^2 + b^2
    double finalAnswer = sqrt(pow(firstInteger, 2.0) + pow(secondInteger, 2.0));

    //outputs the calculation
    std::cout << "The answer, c , is " << finalAnswer << "." << std::endl;

    return 0;

}//end of main
