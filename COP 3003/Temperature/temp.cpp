/**********************************************************
 * file: temp.cpp
 * author: Darren Fulton
 * class: COP 3003 Fall 2022
 * purpose: to find the temperature both Fahrenheit and Celsius equal
 *********************************************************/

#include <iostream>

int main() {

    double celsius, fahrenheit;

    celsius = 100;
    fahrenheit = ((9 * celsius)/5) + 32;

    while (celsius < fahrenheit) {

        celsius--;
        fahrenheit = ((9 * celsius)/5) + 32;

        std::cout << "\nThe temperature in Celsius: " << celsius << std::endl;
        std::cout << "The temperature in Fahrenheit: " << fahrenheit <<std::endl;

    }


    return 0;
}
