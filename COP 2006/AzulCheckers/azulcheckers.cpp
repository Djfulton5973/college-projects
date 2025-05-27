/**********************************************************
 * file: azulcheckers.cpp
 * author: Darren Fulton
 * class: COP 2001 Summer 2022
 * purpose: Azul places students in a checkerboard layout
 *********************************************************/

#include <iostream>

#include "Azul/AzulBasic.h"

// Function Declarations (Prototypes)
//---------------------------------------------------------
void azulCheckerLayout(fgcu::AzulBasic &azul, int &worldRow, int &worldColumn);

// Main
//---------------------------------------------------------
int main() {

    int worldRow, worldColumn;

    // prompt for user input for the size of the world
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> worldRow;
    std::cin >> worldColumn;

    fgcu::AzulBasic azul = fgcu::AzulBasic(worldRow, worldColumn);

    azulCheckerLayout(azul, worldRow, worldColumn);

    return 0;
} // end of main

// Function Definitions
//---------------------------------------------------------
void azulCheckerLayout(fgcu::AzulBasic &azul, int &worldRow, int &worldColumn) {

    bool done = false;
    while (azul.isRunning()) {

        if (!done) {

            if (!azul.frontIsBlocked()) { //when there is no walls in front of Azul

                if (azul.isFacingEast()) {

                    azul.putStudent();

                    //move forward twice
                    if (!azul.frontIsBlocked()) {

                        azul.moveForward();

                    }
                    if (!azul.frontIsBlocked()) {

                        azul.moveForward();

                    }

                } //when Azul is facing east
                else if (azul.isFacingWest()) {

                    //faces Azul north
                    azul.turnLeft();
                    azul.turnLeft();
                    azul.turnLeft();

                    if (azul.frontHasStudents()) { //checks if there is a student above Azul

                        azul.turnLeft();
                        azul.moveForward();

                    }
                    else { //when there is not a student above Azul

                        azul.turnLeft();
                        azul.putStudent();

                        //conditions to make sure Azul is not at a wall when moving
                        if (!azul.frontIsBlocked()) {

                            azul.moveForward();

                        } //move forward once
                        if (!azul.frontIsBlocked()) {

                            azul.moveForward();

                        } //move forward twice if not blocked

                    }

                } // when Azul is facing west

            }
            else if (azul.frontIsBlocked()) { //when Azul is in front of a wall

                if (azul.isFacingEast()) {

                    azul.turnLeft();

                    if (azul.frontHasStudents()) { //checks if there is a student above Azul

                        azul.turnLeft();
                        azul.turnLeft();
                        azul.moveForward();

                    }
                    else { //when there is not a student above Azul

                        azul.turnLeft();

                        if (azul.frontHasStudents()) { //checks if there is a student in front of Azul

                            azul.turnLeft();
                            azul.moveForward();

                        }
                        else { //puts a student to keep up the checker pattern

                            azul.turnLeft();
                            azul.putStudent();
                            azul.moveForward();

                        }

                    }

                    //faces Azul west
                    azul.turnLeft();
                    azul.turnLeft();
                    azul.turnLeft();

                }
                else if (azul.isFacingWest()) {

                    //turn right
                    azul.turnLeft();
                    azul.turnLeft();
                    azul.turnLeft();

                    if (azul.frontHasStudents()) { //checks if there is a student above Azul

                        azul.turnLeft();
                        azul.turnLeft();

                        if (!azul.frontIsBlocked()) { //ensures that Azul does not run into walls

                            azul.moveForward();

                        }

                        //faces Azul east
                        azul.turnLeft();

                    }
                    else { //when there is not a student above Azul

                        azul.putStudent();
                        azul.turnLeft();
                        azul.turnLeft();

                        if (azul.frontIsBlocked()) {

                            azul.moveForward();

                        }

                        //faces Azul east
                        azul.turnLeft();

                    }


                }

            }
            if (azul.getRow() == worldRow - 1 && azul.getColumn() == worldColumn - 1) {

                if (azul.frontIsBlocked()) { //makes sure there is not a row left to do

                    //final check if there is a student above Azul
                    azul.turnLeft();

                    if (!azul.frontHasStudents()) {

                        azul.putStudent();

                    } //finishes checking above Azul

                    azul.turnLeft();
                    azul.turnLeft();
                    azul.turnLeft();

                    done = true;

                }

            }//bottom right corner of the world
            else if (azul.getRow() == worldRow - 1 && azul.getColumn() == 0) {

                if (azul.frontIsBlocked()) { //makes sure there is not a row left to do

                    done = true;

                }

            }//bottom left corner of the world

        }//end of while loop

    }//keeps the window running

}//end of azulCheckerLayout