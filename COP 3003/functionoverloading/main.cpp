#include <iostream>

class Modulus {
public:

    void modulus(int x, int y) {

        std::cout << x % y << std::endl;

    }
    //Overloading, the constructor gets a secondary function
    void modulus() {

        std::cout << "Modulus function." << std::endl;

    }


};

int main() {

    Modulus n1;

    //The function without parameters is called
    n1.modulus();

    //The function that accept arguments is called
    n1.modulus(15,2);

    return 0;
}
