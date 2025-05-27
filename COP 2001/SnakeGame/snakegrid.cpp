#include <iostream>

#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>

#include <cstdlib>
#include <chrono>


const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

const int SNAKE_SIZE = 30;

enum Direction {
    North,
    East,
    South,
    West
};

enum Turn {
    Counterclockwise = -1,
    NoTurn,
    Clockwise
};

bool goDirection(Direction direction, int &cellX, int &cellY, int rows, int columns);

int main() {

    fgcu::AnimatedWindow window(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game Example");
    window.setColor(sf::Color::Black);

    int rows = WINDOW_HEIGHT / SNAKE_SIZE;
    int columns = WINDOW_WIDTH / SNAKE_SIZE;

    fgcu::AnimatedRectangle snake[rows * columns];
    int snakeLength = 0;
    Direction snakeDirection = North;
    int snakeXCell = columns / 2;
    int snakeYCell = rows / 2;


    int x = snakeXCell;  // middle column
    int y = snakeYCell; // middle row

    for (int i= 0; i < 5; i++) {
        snake[snakeLength] = fgcu::AnimatedRectangle(SNAKE_SIZE, SNAKE_SIZE);
        snake[snakeLength].setOrigin(SNAKE_SIZE / 2, SNAKE_SIZE / 2);
        snake[snakeLength].setPosition(x * SNAKE_SIZE, y * SNAKE_SIZE);
        snake[snakeLength].setFillColor(sf::Color::Green);
        window.addShape(&snake[snakeLength]);
        snakeLength++;
        y++;
    }

    std::srand(std::time(NULL));    // init random number generator

    auto startTime = std::chrono::high_resolution_clock::now();
    int elapsed_ms = 0;

    while(window.nextFrame()) {
        auto stopTime = std::chrono::high_resolution_clock::now();
        elapsed_ms += std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();

        startTime = stopTime;

        if (elapsed_ms >= 100) {
            elapsed_ms = 0;

            // move each body part to the position of the one in front of it
            // from the tail to the head
            for (int i = snakeLength - 1; i > 0; i--) {
                snake[i].setPosition(snake[i-1].getPosition());
            }

            // pick a random turn for the head
            int turn = 0;
            sf::Keyboard::Key input = window.getLastKey();

            // try to turn or move the head in the direction it is going and a clock turn
            switch(snakeDirection) {

                case North:

                    switch (input) {
                        case Counterclockwise:
                            if (goDirection(West, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = West;
                            break;

                        case Clockwise:
                            if (goDirection(East, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = East;
                            break;

                        default: // none
                            goDirection(North, snakeXCell, snakeYCell, rows, columns);

                    } // North turn
                    break;

                case East:

                    switch (input) {
                        case Counterclockwise:
                            if (goDirection(North, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = North;
                            break;

                        case Clockwise:
                            if (goDirection(South, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = South;
                            break;

                        default: // none
                            goDirection(South, snakeXCell, snakeYCell, rows, columns);

                    } // East turn
                    break;

                case South:

                    switch (input) {
                        case Counterclockwise:
                            if (goDirection(East, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = East;
                            break;

                        case Clockwise:
                            if (goDirection(West, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = West;
                            break;

                        default: // none
                            goDirection(South, snakeXCell, snakeYCell, rows, columns);

                    } // South turn
                    break;

                default: // West

                    switch (input) {

                        if (sf::Keyboard::S || sf::Keyboard::Down) {

                            turn = -1;

                        }

                        case Counterclockwise:
                            if (goDirection(South, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = South;
                            break;

                        case Clockwise:
                            if (goDirection(North, snakeXCell, snakeYCell, rows, columns))
                                snakeDirection = North;
                            break;

                        default: // none
                            goDirection(West, snakeXCell, snakeYCell, rows, columns);

                    } // West turn

            } // snake direction


            // set the head to its new position
            snake[0].setPosition(snakeXCell * SNAKE_SIZE, snakeYCell * SNAKE_SIZE);


        } // seconds



    } // next frame


    return 0;
} // end main


bool goDirection(Direction direction, int &cellX, int &cellY, int rows, int columns) {
    bool moved = false;

    switch (direction) {
        case North:
            if (cellY > 0) {
                cellY--;
                moved = true;
            }
            break;
        case East:
            if (cellX < columns - 1) {
                cellX++;
                moved = true;
            }
            break;
        case South:
            if (cellY < rows - 1) {
                cellY++;
                moved = true;
            }
            break;
        default: // West
            if (cellX > 0) {
                cellX--;
                moved = true;
            }
    }
} // goDirection