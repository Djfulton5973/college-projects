//    file: main.cpp
//  author: "Put your name here"
//   class: COP 2001, Summer B 2022
// Purpose: make Azul pick up a student cap and carry it up
//          a step
// --------------------------------------------------------

#include <iostream>
#include <Azul/AzulStep.h>

int main() {

    // default world rows=9, columns=9
    fgcu::AzulStep azul = fgcu::AzulStep();


    bool done = false;
    while(azul.isRunning()) {

        // process tasks until finished

        if (!done) {
            // pick up the student in the next cell
            azul.moveForward();
            azul.pickStudent();

            // go to the step
            while (!azul.frontIsBlocked()) {
                azul.moveForward();
            }

            // move up the step
            azul.turnLeft();
            azul.moveForward();
            // turn right
            azul.turnLeft();
            azul.turnLeft();
            azul.turnLeft();

            // move to 2nd cell on step and put the student down
            azul.moveForward();
            azul.moveForward();
            azul.putStudent();

            // now move to end
            while (!azul.frontIsBlocked()) {
                azul.moveForward();
            }

            done = true;
        } // not done

        // stay in loop to keep window alive

    } // not closing

    return 0;
} // end main
