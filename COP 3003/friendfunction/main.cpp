#include <iostream>
class FindMax1 {

    int x = 0;

public:

    FindMax1() {

        std::cout << "\nEnter a number:\n";
        std::cin >> x;

    }
    friend void maxNum();

};

class FindMax2 {

    int y = 0;

public:

    FindMax2() {

        std::cout << "\nEnter a number:\n";
        std::cin >> y;

    }
    friend void maxNum();

};

void maxNum();

int main() {

    maxNum();

    return 0;
}

void maxNum() {

    FindMax1 n1;
    FindMax2 n2;

    if (n1.x > n2.y)
        std::cout << "The maximum is " << n1.x << "." << std::endl;
    else
        std::cout << "The maximum is " << n2.y << "." << std::endl;

}
