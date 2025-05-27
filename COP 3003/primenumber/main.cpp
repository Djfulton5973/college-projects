#include <iostream>
int checkNumber(int);
void isNotPrime();
int isPrime();
void fairWarning(int);

int main() {

    int x = 0;

    checkNumber(x);
    
    return 0;
}

int checkNumber(int a) {

    std::cout << "Enter an integer: ";
    std::cin >> a;

    if (a == 2 || a == 3 || a == 5 || a == 7)
        isPrime();
    else if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0)
        isNotPrime();
    else if (a <= 1)
        fairWarning(a);
    else
        isPrime();

    return 0;
}

void isNotPrime() {

    std::cout << "It is not a prime number." << std::endl;

}

int isPrime() {

    std::cout << "It is a prime number." << std::endl;

    return 0;
}

void fairWarning(int a) {

    std::cout << "The value inputted is invalid."
                 "Try again." << std::endl;

    checkNumber(a);

}
