#include <iostream>

int digSum(int);

int main() {

    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << digSum(number);

    return 0;
}

int digSum(int n) {

    int sum = 0;

    // checks if it is a single digit every time
    while (n > 0 || sum > 9) {

        if (n == 0) {

            n = sum;
            sum = 0;

        }

        sum += n % 10;
        n /= 10;

    }

    return sum;

}
