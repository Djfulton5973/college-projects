/**********************************************************
* file: drawingexample.cpp
* author: Darren Fulton
* class: COP 2001 Summer 2022
* purpose: exercise sfml
**********************************************************/

#include <iostream>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SPEED = 35;

struct Rectangle {
    int width;
    int height;
    int x;
    int y;
};

int main() {

    fgcu::AnimatedWindow window = fgcu::AnimatedWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Goofy Ahh");
    window.setColor(sf::Color::Black);

    Rectangle rectangleBounds = {100, 50, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    fgcu::AnimatedRectangle rectangle = fgcu::AnimatedRectangle(rectangleBounds.width, rectangleBounds.height);
    rectangle.setOrigin(rectangleBounds.width / 2, rectangleBounds.height / 2);
    rectangle.setPosition(rectangleBounds.x, rectangleBounds.y);
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setRotationalSpeed(10);

    window.addShape(&rectangle);

    while (window.nextFrame()) {

        switch (window.getLastKey()) {
            case sf::Keyboard::Left:
            case sf::Keyboard::A:
                rectangle.setHorizontalSpeed(SPEED * -1);
                break;
            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                rectangle.setHorizontalSpeed(SPEED);
                break;
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                rectangle.setVerticalSpeed(SPEED * -1);
                break;
            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                rectangle.setVerticalSpeed(SPEED);
                break;
            case sf::Keyboard::Space:
                rectangle.setHorizontalSpeed(0);
                rectangle.setVerticalSpeed(0);
        } // key switch

        //window.draw(rectangle);

    }

    return 0;
}
