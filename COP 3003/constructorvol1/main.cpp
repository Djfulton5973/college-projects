#include <iostream>

class Volume {
public:

    int a = 5;
    int b = 7;
    int c = 9;

    Volume() {

        std::cout << "The volume is " << a*b*c;

    }

};

int main() {

    Volume myObj;

    return 0;
}
