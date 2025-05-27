#include <iostream>

void numberOfDays(int);

int main() {

    int userInput;

    std::cout << "Enter a number from 1 through 12 "
                 "(January through December):";
    std::cin >> userInput;

    numberOfDays(userInput);

    return 0;
}

void numberOfDays(int month) {

    if (month == 2) { // February

        std::cout << "This month has 28 days on a common year,\n"
                     "29 days on a leap year." << std::endl;

    }
    else if (month == 1 || month == 3 || month == 5
    || month == 7 || month == 8 || month == 10 || month == 12)

        std::cout << "This month has 31 days." << std::endl;

    else if (month == 4 || month == 6 || month == 9 || month == 11)

        std::cout << "This month has 30 days." << std::endl;

    else { // user inputted a number less than 1 or greater than 12

        std::cout << "Try again." << std::endl;
        std::cout << "Enter a number from 1 through 12 "
                     "(January through December):";
        std::cin >> month;

        // recursive call to use new input
        numberOfDays(month);

    }

}