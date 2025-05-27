#include <iostream>

#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedCircle.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int WALL_THICKNESS = 10;

const sf::Color WALL_COLOR = sf::Color::Blue;

const int SPEED = 100;

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

struct Snake {
    fgcu::AnimatedRectangle shape;
    Direction direction;

};

int main() {

    fgcu::AnimatedWindow window(WINDOW_WIDTH, WINDOW_HEIGHT, "Snake Game");
    window.setColor(sf::Color::Black);

    int snakeLength = 0;

    int snakeSize = 30;

    Snake body;
    body.shape = fgcu::AnimatedRectangle [50]

    return 0;
}
