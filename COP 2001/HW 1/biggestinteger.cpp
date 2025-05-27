/**********************************************************
 * file: biggestinteger.cpp
 * author: Darren Fulton
 * class: COP 2001 Summer 2022
 * purpose: find the largest integer out the given three
 *********************************************************/

#include <iostream>

int main() {

    int integerOne, integerTwo, integerThree;

    //prompts user for three values
    std::cout << "Enter three different integers:" << std::endl;
    std::cin >> integerOne;
    std::cin >> integerTwo;
    std::cin >> integerThree;

    int maxInteger; //the variable that is compared
    if (integerOne > integerTwo) { //checks if the first integer is the biggest

        maxInteger = integerOne;
        if (integerOne > integerThree) { //compares the last integer left

            std::cout << "Max number is " << maxInteger << ".";

        }
        else { //assumes that the third integer is the biggest

            maxInteger = integerThree;
            std::cout << "Max number is " << maxInteger << ".";

        }

    } //the first two integers are compared
    else { //assumes the second integer is bigger than the first

        maxInteger = integerTwo;
        if (integerTwo > integerThree) { //compares to the last integer left

            std::cout << "Max number is " << maxInteger << ".";

        }
        else { //assumes that the third integer is the biggest

            maxInteger = integerThree;
            std::cout << "Max number is " << maxInteger << ".";

        }

    }

    return 0;
} //end of main
