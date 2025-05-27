/**********************************************************
 * file: theminandmax.cpp
 * author: Darren Fulton
 * class: COP 2001 Summer 2022
 * purpose: get the minimum and the maximum from a list
 *********************************************************/

#include <iostream>

int main() {

    int currentInteger;
    int minInteger;
    int maxInteger;
    int count = 0; //keeps track the amount of loops
    bool Finished = false;

    while (!Finished) {

        //prompts user until the trigger value is used
        std::cout << "Enter an integer > 0 (-1 to stop): \n";
        std::cin >> currentInteger;
        count++;

        if (count == 1 && currentInteger != -1) {

            if (currentInteger != 0) { //value must be greater than 0

                //updates the minimum and maximum for the first time
                minInteger = currentInteger;
                maxInteger = currentInteger;

            }
            else { //inputting 0 does not count towards the loop

                count--;

            }

        }
        else if (currentInteger == -1 && count > 1) {

            Finished = true;

        } //ends while loop when at least one valid value went through
        else if (currentInteger == -1) {

            //occurs when user does not input any other values before the trigger value
            std::cout << "There were no numbers entered." << std::endl;
            count--;

        }
        else if (currentInteger >= maxInteger) { //input updates the maximum value

            if (currentInteger != -1) { //input must not be the trigger value

                maxInteger = currentInteger;

            }

        } //changes the maximum value
        else if (currentInteger <= minInteger) { //input updates the minimum value

            if (currentInteger != -1) { //input must not be the trigger value

                if (currentInteger != 0) { //value must be bigger than 0

                    minInteger = currentInteger;

                }

            }
        } //changes the minimum value

    }//end of while loop

    //displays the minimum and maximum values
    std::cout << "Min value is: " << minInteger << std::endl;
    std::cout << "Max value is: " << maxInteger << std::endl;

    return 0;
}//end of main
