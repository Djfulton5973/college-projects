/**********************************************************
* file: drawinghouse.cpp
* author: Darren Fulton
* class: COP 2001 Summer 2022
* purpose: to create a 2D house using SFML
**********************************************************/

#include <iostream>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedTriangle.h>
#include <Eagles/AnimatedCircle.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int GRASS_HEIGHT = 20;// used to make height changes easier

struct Block {

    int width;
    int height;
    int x;
    int y;

};

int main() {

    fgcu::AnimatedWindow window = fgcu::AnimatedWindow{WINDOW_WIDTH, WINDOW_HEIGHT,"House"};

    // the grass under the house
    Block grassFloor = {WINDOW_WIDTH, GRASS_HEIGHT, WINDOW_WIDTH / 2, WINDOW_HEIGHT};

    fgcu::AnimatedRectangle grass = fgcu::AnimatedRectangle(grassFloor.width, grassFloor.height);
    grass.setOrigin(grassFloor.width / 2, grassFloor.height);
    grass.setPosition(grassFloor.x, grassFloor.y);
    grass.setFillColor(sf::Color::Green);

    // the body of the house
    Block houseBody ={350, 200, WINDOW_WIDTH / 2, WINDOW_HEIGHT};
    
    fgcu::AnimatedRectangle body = fgcu::AnimatedRectangle(houseBody.width,houseBody.height);
    body.setOrigin(houseBody.width / 2, GRASS_HEIGHT + houseBody.height);// grass moves the body up
    body.setPosition(houseBody.x, houseBody.y);
    body.setFillColor(sf::Color::Blue);

    // the door
    Block houseDoor = {60, houseBody.height / 2, WINDOW_WIDTH / 2, WINDOW_HEIGHT - GRASS_HEIGHT};
    // the door is just above grass and moves along with it

    fgcu::AnimatedRectangle door = fgcu::AnimatedRectangle(houseDoor.width, houseDoor.height);
    door.setOrigin(houseDoor.width / 2, 0);
    door.setPosition(houseDoor.x, houseDoor.y - houseDoor.height);
    door.setFillColor(sf::Color::Red);

    // structure for the windows
    Block houseWindow = {60, 60, houseBody.x, WINDOW_HEIGHT - houseBody.height / 4};

    // the left window
    fgcu::AnimatedRectangle windowLeft = fgcu::AnimatedRectangle(houseWindow.width, houseWindow.height);
    windowLeft.setOrigin(135, 40);
    windowLeft.setPosition(houseWindow.x, houseWindow.y - GRASS_HEIGHT);// left window moves along the grass
    windowLeft.setFillColor(sf::Color::White);

    // the right window
    fgcu::AnimatedRectangle windowRight = fgcu::AnimatedRectangle(houseWindow.width, houseWindow.height);
    windowRight.setOrigin( -75, 40);
    windowRight.setPosition(houseWindow.x, houseWindow.y - GRASS_HEIGHT);// right window moves along the grass
    windowRight.setFillColor(sf::Color::White);

    // the roof
    Block houseRoof = {400, 100, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};

    fgcu::AnimatedTriangle roof = fgcu::AnimatedTriangle(houseRoof.width, houseRoof.height);
    roof.setOrigin(houseRoof.width / 2,GRASS_HEIGHT);// roof moves along the grass
    roof.setPosition(houseRoof.x, houseRoof.y);
    roof.setFillColor(sf::Color::Magenta);

    // the sun
    fgcu::AnimatedCircle sun = fgcu::AnimatedCircle(45,30);
    sun.setPosition(100, 100);
    sun.setFillColor(sf::Color::Yellow);

    while (window.nextFrame()) {

        // displays all the shapes
        window.draw(grass);
        window.draw(body);
        window.draw(door);
        window.draw(windowLeft);
        window.draw(windowRight);
        window.draw(roof);
        window.draw(sun);

    }// the window runs indefinitely with the loop

    return 0;
}// end of main
