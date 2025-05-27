#include <iostream>

class alpha {
public:

    alpha() {
        std::cout << "In Alpha." << std::endl;
    }

};

class beta {
public:

    beta() {
        std::cout << "In Beta." << std::endl;
    }

};

class gamma : public alpha, public beta {
public:

    gamma() {
        std::cout << "In Gamma." << std::endl;
    }

};

int main() {

    gamma g1;

    return 0;
}
