#include <iostream>

class Counter {
public:

    static int count;

    Counter() {

        count++;

    }

};

int Counter::count = 0;

int main() {

    Counter c1;
    Counter c2;
    Counter c3;

    std::cout << "Count = " << Counter::count;

    return 0;
}
