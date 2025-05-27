#include <iostream>

class Fib {
    //two members
    int x, y;
public:

    Fib() {

        //the two members are initialized
        x = -1;
        y = 1;

    }

    // the function that displays the Fibonacci Series
    void showFib(int n) {

        std::cout << "The Fibonacci Series for the number " << n << ":" << std::endl;

        int hold;

        for (int i = 0; i < n; ++i) {

            hold = x+y;
            x = y;
            y = hold;

            std::cout << " " << hold;

        }

    }


};

int main() {

    int n;

    std::cout << "Enter a number for the amount of terms:";
    std::cin >> n;

    Fib fib1;
    fib1.showFib(n);

    return 0;
}
