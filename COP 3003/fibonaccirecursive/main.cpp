#include <iostream>

int fibonacci(int x);

int main() {

    int x;

    std::cout << "Enter a number for the amount of terms: ";
    std::cin >> x;

    for (int i = 0; i < x; ++i) {
        std::cout << "\n " << fibonacci(i);
    }

    return 0;
}

int fibonacci(int x) {

    if (x <= 1)
        return x;
    else
        return fibonacci(x-1) + fibonacci(x-2);

}