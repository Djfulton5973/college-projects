#include <iostream>

class Employee { //base class
private:

    double salary;

public:

    void showSalary(double d) {

        salary = d;

        std::cout << "This employee makes $" << salary << " per hour." << std::endl;

    }

};
class Outside : public Employee { //hierarchical inheritance
public:

    void workOutside() {

        std::cout << "They are outside, possibly on a break or fetching carts." << std::endl;

    }

};



class Cashier : public Employee { //hierarchical inheritance
public:

    void talk() {

        std::cout << "They engage with the customers at the lines." << std::endl;

    };

};
class Bagger : public Cashier { //multilevel inheritance
public:

    void bag() {

        std::cout << "They place the scanned items in the plastic bags." << std::endl;

    }

};

int main() {

    Bagger e1;

    std::cout << "Employee #1" << std::endl;

    e1.showSalary(5.00);
    e1.talk();
    e1.bag();

    Outside e2;

    std::cout << "Employee #2" << std::endl;

    e2.showSalary(4.50);
    e2.workOutside();

    return 0;
}
