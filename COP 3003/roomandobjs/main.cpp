#include <iostream>

class Room {
public:

    void areaCal(double l, double b) {

        double area = l * b;
        std::cout << "\nArea = " << area;

    }
    void volumeCal(double w, double c, double p) {

        double volume = w * c * p;
        std::cout << "\nVolume = " << volume;

    }

};

int main() {

    Room r1;
    Room r2;
    Room r3;

    std::cout << "\nRoom 1: ";
    r1.areaCal(4.0, 5.0);
    r1.volumeCal(7.0, 4.0, 5.0);

    std::cout << "\nRoom 2: ";
    r2.areaCal(8.0, 9.0);
    r2.volumeCal(6.0, 8.0, 9.0);

    std::cout << "\nRoom 3: ";
    r3.areaCal(2.0, 3.0);
    r3.volumeCal(10.0, 2.0, 3.0);


    return 0;
}
