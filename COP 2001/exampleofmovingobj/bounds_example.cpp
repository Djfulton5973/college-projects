#include <iostream>
#include <Eagles/AnimatedWindow.h>
#include <Eagles/AnimatedRectangle.h>
#include <Eagles/AnimatedCircle.h>
#include <Eagles/Bounds.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int RECTANGLE_WIDTH = 40;
const int RECTANGLE_HEIGHT = 20;

const int CIRCLE_RADIUS = 15;

const int PADDING = 30;

enum Position {
    None,
    LeftOf,
    Above,
    RightOf,
    Below,
    Center,
    Middle
};

struct Ball {
    fgcu::AnimatedCircle shape;
    Position alignHorizontal;
    Position alignVertical;
};

void printBounds(fgcu::Bounds bounds);

int main() {

    fgcu::AnimatedWindow window(WINDOW_WIDTH, WINDOW_HEIGHT, "Position Using Bounds");
    window.setColor(sf::Color(175, 209, 96));


    // setup the rectangle
    fgcu::AnimatedRectangle rectangle(RECTANGLE_WIDTH, RECTANGLE_HEIGHT);
    // position it in middle of the window
    rectangle.setPosition(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0);
    rectangle.setFillColor(sf::Color(175,96,209));
    // add shape to window
    window.addShape(&rectangle);


    // setup the ball
    Ball ball;
    // set both horiz and vert to not aligned
    ball.alignHorizontal = None;
    ball.alignVertical = None;
    // instantiate the ball shape
    ball.shape = fgcu::AnimatedCircle(CIRCLE_RADIUS);
    //set origin to center of circle
    ball.shape.setOrigin(CIRCLE_RADIUS,CIRCLE_RADIUS);
    // start ball in top left corner of window (i.e. put center/middle in 1-radius each)
    ball.shape.setPosition(CIRCLE_RADIUS, CIRCLE_RADIUS);
    ball.shape.setFillColor(sf::Color(242,111,46));
    // add shape to window
    window.addShape(&ball.shape);
    
    
    while(window.nextFrame()) {
        
        sf::Keyboard::Key input = window.getLastKey();
        
        
        // skip if no user input:
        if (input != sf::Keyboard::Unknown) {

            // get current shape bounds before update:

            // get bounds of the rectangle (pass in global bounds and position)
            fgcu::Bounds rectangleBounds(rectangle.getGlobalBounds(), rectangle.getPosition());

            // get bounds of the ball shape (pass in global bounds and position)
            fgcu::Bounds circleBounds(ball.shape.getGlobalBounds(), ball.shape.getPosition());


            // print starting bounds
            std::cout << "Before move: \n";
            std::cout << "R: ";
            printBounds(rectangleBounds);
            std::cout << "C: ";
            printBounds(circleBounds);
            std::cout << std::endl;


            switch (input) {
                // move ball upwards
                case sf::Keyboard::W:
                case sf::Keyboard::Up:

                    // ignore if above
                    if (ball.alignVertical != Above) {

                        // in currently in middle then move above
                        if (ball.alignVertical == Middle) {
                            circleBounds.toTopOf(rectangleBounds, PADDING);
                            // update alignment state
                            ball.alignVertical = Above;
                        }
                            // below or none align to middle
                        else {
                            circleBounds.alignMiddle(rectangleBounds);
                            // update alignment state
                            ball.alignVertical = Middle;
                        }
                    }
                    break;

                    // move ball left    
                case sf::Keyboard::A:
                case sf::Keyboard::Left:

                    // ignore if left
                    if (ball.alignHorizontal != LeftOf) {

                        // in center then move left
                        if (ball.alignHorizontal == Center) {
                            circleBounds.toLeftOf(rectangleBounds, PADDING);
                            // update alignment state
                            ball.alignHorizontal = LeftOf;
                        }
                            // right or none align to center
                        else {
                            circleBounds.alignCenter(rectangleBounds);
                            // update alignment state
                            ball.alignHorizontal = Center;
                        }
                    }
                    break;

                    // move ball down    
                case sf::Keyboard::S:
                case sf::Keyboard::Down:

                    // ignore if below
                    if (ball.alignVertical != Below) {

                        // in currently in middle then move down
                        if (ball.alignVertical == Middle) {
                            circleBounds.toBottomOf(rectangleBounds, PADDING);
                            // update alignment state
                            ball.alignVertical = Below;
                        }
                            // above or none align to middle
                        else {
                            circleBounds.alignMiddle(rectangleBounds);
                            // update alignment state
                            ball.alignVertical = Middle;
                        }
                    }
                    break;

                    // move ball right
                case sf::Keyboard::D:
                case sf::Keyboard::Right:

                    // ignore if right
                    if (ball.alignHorizontal != RightOf) {

                        // in center then move right
                        if (ball.alignHorizontal == Center) {
                            circleBounds.toRightOf(rectangleBounds, PADDING);
                            // update alignment state
                            ball.alignHorizontal = RightOf;
                        }
                            // left or none align to center
                        else {
                            circleBounds.alignCenter(rectangleBounds);
                            // update alignment state
                            ball.alignHorizontal = Center;
                        }
                    }
                    break;
                    
                default:
                    // default input for non-handled keys
                    input = sf::Keyboard::Unknown;

            } // process user input


            // get updated shape bounds after moving:
            if (input != sf::Keyboard::Unknown) { // not a valid movement key

                // _______________________________________________________
                // move the ball
                // update position of ball using new (x,y) in circleBounds
                // _______________________________________________________
                ball.shape.setPosition(circleBounds.x, circleBounds.y);


                // print starting bounds
                std::cout << "Before move: \n";
                std::cout << "R: ";
                printBounds(rectangleBounds);
                std::cout << "C: ";
                printBounds(circleBounds);
                std::cout << std::endl;

            } // valid input check

        } // check for user input

        
    } // next frame

    return 0;
}

void printBounds(fgcu::Bounds bounds) {
    std::cout << " L=" << bounds.left
              << " T=" << bounds.top
              << " c=" << bounds.center
              << " m=" << bounds.middle
              << " r=" << bounds.right
              << " b=" << bounds.bottom
              << " x=" << bounds.x
              << " y=" << bounds.y
              << " ox=" << bounds.originX
              << " oy=" << bounds.originY
              << std::endl;
}