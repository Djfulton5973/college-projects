#include <iostream>

inline int sum(int a, int b, int c, int d, int e) {
    return (a+b+c+d+e);
}
inline int multiply(int a, int b, int c, int d, int e) {
    return  (a*b*c*d*e);
}


int main() {

    int a, b, c, d, e;

    std::cout << "\nEnter your first number: ";
    std::cin >> a;

    std::cout << "\nEnter your second number: ";
    std::cin >> b;

    std::cout << "\nEnter your third number: ";
    std::cin >> c;

    std::cout << "\nEnter your fourth number: ";
    std::cin >> d;

    std::cout << "\nEnter your last number: ";
    std::cin >> e;

    std::cout << "\nThe sum of the five numbers = " << sum(a,b,c,d,e);
    std::cout << "\nThe product of the five numbers = " << multiply(a,b,c,d,e);

    return 0;
}
