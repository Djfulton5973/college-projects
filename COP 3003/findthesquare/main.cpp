#include <iostream>

void returnRef(int &value);
void returnValue(int *ptr_int);
int squaredValue(int number);

int main() {

    int valueOne = 9;

    std::cout << "The value is " << valueOne << ".\n";

    returnRef(valueOne);

    std::cout << "By return by reference, it is squared: " << valueOne << ".\n";
    
    int valueTwo = 12;
    int *ptr_value = &valueTwo;

    std::cout << "The value is " << valueTwo << ".\n";

    returnValue(ptr_value);

    std::cout << "By return by value (pointer), it is squared: " << valueTwo << ".\n";

    int valueThree = 3;

    std::cout << "The value is " << valueThree << ".\n";

    std::cout << "By the function prototype, it is squared: " << squaredValue(valueThree) << ".\n";

    return 0;
}

void returnRef(int &value) {

    value = value * value;

}

void returnValue(int *ptr_int) {
    
    *ptr_int = *ptr_int * *ptr_int;

}

int squaredValue(int number) {

    int result = number * number;

    return result;
}