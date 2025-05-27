#include <iostream>

class Division {
    float n;
public:

    Division(){};

    //Overloading function, function that is only accessed when assigning a number
    Division(float n) {

        //Assigns the n of the constructor to be the same n that is private
        this->n = n;

    };

    //An operator that only works with objects of the Division class
    Division operator /(Division y) {

        Division z;
        z.n = n / y.n;

    }

    void print() {

        std::cout << "The number is " << n << "." << std::endl;

    }

};

int main() {

    Division a(7.0);
    Division b(2.0);

    //The n of c is updated once the operator is used
    Division c = a / b;

    c.print();

    return 0;
}
