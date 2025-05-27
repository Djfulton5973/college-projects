#include <iostream>

class Hospital { //the base class
public:

    Hospital() { //A message to show that we are in the base class

        std::cout << "In a hospital." << std::endl;

    }

};

class Patient : public Hospital { //inherits from the base class

    int costs;

public:

    void setBills(int c) { //sets the inputted value for the bills

        costs = c;

        std::cout << "Inputting bills..." << std::endl;

    }

    void getBills() { //displays costs, a value only accessible in the class

        std::cout << "The bills cost $" << costs << "." << std::endl;

    }

};

class Sick : public Patient { //inherits the derived class above
public:

    Sick() { //A message to show we are in the derived class Sick

        std::cout << "A very sick patient." << std::endl;

    }

};

int main() {

    Sick p1;
    p1.setBills(1500);
    p1.getBills();

    return 0;
}
