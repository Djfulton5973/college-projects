#include <iostream>
#include <iomanip>
#include <cmath>

int main() {

    double dollars, reals, euros, can_Dollars, pesos, rupees, convertedMon;

    reals = 5.18;
    euros = 0.99;
    can_Dollars = 1.31;
    pesos = 20.15;
    rupees = 79.55;

    std::cout << "Enter the number of dollars you want to convert: $";
    std::cin >> dollars;

    std::cout << "\nDollars in other currencies: " << std::endl;

    std::cout << std::setprecision(2) << std::fixed;

    convertedMon = dollars * reals;
    std::cout << "\nIn Reals: " << convertedMon;

    convertedMon = dollars * euros;
    std::cout << "\nIn Euros: " << convertedMon;

    convertedMon = dollars * can_Dollars;
    std::cout << "\nIn Canadian Dollars: " << convertedMon;

    convertedMon = dollars * pesos;
    std::cout << "\nIn Pesos: " << convertedMon;

    convertedMon = dollars * rupees;
    std::cout << "\nIn Rupees: " << convertedMon;

    return 0;
}
