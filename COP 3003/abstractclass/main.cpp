#include <iostream>

class Patient {
public:

    //The pure virtual function that makes the base class abstract
    virtual void status() = 0;

};

class Sick : public Patient {
public:

    //Needs the function overwritten, otherwise it throws a compile error
    void status() {
        std::cout << "The patient is sick." << std::endl;
    }

};

int main() {

    //pointer points to the address of allocated memory of the derived class
    Patient* patient_ptr = new Sick();

    //Used the function within the derived class, and not in the base class
    patient_ptr->status();

    return 0;
}
