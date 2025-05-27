#include <iostream>
int findFact(int results);

int main() {

    int number = 5;

    std::cout << "The factorial of " << number << "!: \n";

    for (int i = number; i > 0; --i) {

        if (i - 1 != 0)
            std::cout << i << " * ";
        else
            std::cout << i << " or ";

    }

    std::cout << findFact(number);

    return 0;
}
int findFact(int results) {

    if (results > 1)
        return results * findFact(results - 1);
    else
        return 1;

}