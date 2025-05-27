#include <iostream>

int main() {

    char letter;

    std::cout << "Enter a letter:";
    std::cin >> letter;

    // checks for the vowels
    if (letter == 'a' || letter == 'e' || letter == 'i' ||
        letter == 'o' || letter == 'u' || letter == 'A' || letter == 'E' ||
        letter == 'I' || letter == 'O' || letter == 'U') {

        std::cout << "It is a vowel." << std::endl;

    } else
        std::cout << "It is a consonant." << std::endl;

    return 0;
}
