#include <iostream>

class Volume {
public:

    Volume(int a, int b, int c) {

        std::cout << "The volume is " << a*b*c;

    }

};

int main() {

    Volume myObj(5,7,9);

    return 0;
}
