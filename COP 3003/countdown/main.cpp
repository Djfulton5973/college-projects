#include <iostream>

class Count {
    static int count;
public:

    Count() {

        ++count;

    }

    static void showcount() {

        std::cout << "The count is currently at " << count << "." << std::endl;

    }

};

int Count::count = 0;

int main() {

    Count obj1;

    Count::showcount();

    Count obj2, obj3;

    Count::showcount();

    return 0;
}
