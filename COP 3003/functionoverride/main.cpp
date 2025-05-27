#include <iostream>

class Patient {
public:

    //The function that wants to be overwritten
    virtual void status() {
        std::cout << "The patient exists." << std::endl;
    }

};

class Healthy : public Patient {
public:

    //The function in the derived class overwrites the base class's function
    void status() {
        std::cout << "The patient is fine." << std::endl;
    }

};

int main() {

    //Create a variable with the derived class and its overriding function
    Healthy p1;

    //Using a pointer that has the Base class to point to the derived variable's address
    Patient* patient1 = &p1;

    //When called, it uses the overriding function of status()
    patient1->status();

    return 0;
}
