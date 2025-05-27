#include <iostream>
#include <cmath>

inline void shape(int x) {
    std::cout << "The area of the square is " << x * x << "." << std::endl;
}
inline void shape(int x, int y) {
    std::cout << "The area of the rectangle is " << x * y << "." << std::endl;
}
inline void shape(double r) {
    std::cout << "The area of the circle is " << M_PI * r * r << "." << std::endl;
}
inline void shape(double x, double y) {
    std::cout << "The area of the triangle is " << 0.5 * x * y << "." << std::endl;
}

int main() {

    shape(5);
    shape(3,4);
    shape(7.0);
    shape(6.5,8.5);

    return 0;
}
