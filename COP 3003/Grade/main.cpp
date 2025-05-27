/**********************************************************
 * file: grade.cpp
 * author: Darren Fulton
 * class: COP 3003 Fall 2022
 * purpose: to show the letter grade based on input
 *********************************************************/

#include <iostream>

int main() {

    int grade;
    char letter;

    std::cout << "Enter a number to check the grade:";
    std::cin >> grade;

    if (grade < 59)
        letter = 'F';

    else if (grade < 69)
        letter = 'D';

    else if (grade < 79)
        letter = 'C';

    else if (grade < 89)
        letter = 'B';

    else
        letter = 'A';

    std::cout << "You currently have the letter grade " << letter << "." << std::endl;
    
    return 0;
}
