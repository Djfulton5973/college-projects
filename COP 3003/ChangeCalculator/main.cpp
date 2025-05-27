#include <iostream>

struct value {
    float quarter = 0.25;
    float dime = 0.10;
    float nickel = 0.05;
};

class change {
    public:
    int quarter;
    int dime;
    int nickel;
};

int main() {

    value realCost;
    change realAmount;

    std::cout << "How many quarters do you have?: ";
    std::cin >> realAmount.quarter;

    std::cout << "How many dimes do you have?: ";
    std::cin >> realAmount.dime;

    std::cout << "How many nickels do you have?: ";
    std::cin >> realAmount.nickel;

    float monetaryValue = 0.0f;

    monetaryValue += realCost.quarter * realAmount.quarter;

    monetaryValue += realCost.dime * realAmount.dime;

    monetaryValue += realCost.nickel * realAmount.nickel;

    std::cout << "You have a total of $" << monetaryValue << std::endl;

    return 0;
}
