#include <iostream>
int findMax(int list[5]);
int findMin(int list[5]);

int main() {

    int myNumbers[5] = {5, 8, 9,3,4};

    std::cout << "The maximum number is " << findMax(myNumbers) << ".\n";

    std::cout << "The minimum number is " << findMin(myNumbers) << ".";

    return 0;
}

int findMax(int list[5]) {

    int max = list[0];
    for (int i = 0; i < 5; ++i) {
        if (max < list[i])
            max = list[i];
    }

    return max;
}

int findMin(int list[5]) {

    int min = list[0];
    for (int i = 0; i < 5; ++i) {
        if (min > list[i])
            min = list[i];
    }

    return min;
}