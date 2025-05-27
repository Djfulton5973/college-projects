#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    char user, computer;
    int randNum;

    // generates a random number
    srand(time(0));

    // computer makes a choice
    randNum = rand() % 3; // 0, 1, 2

    // convert to char
    if (randNum == 0)
        computer = 'R';
    else if (randNum == 1)
        computer = 'P';
    else
        computer = 'S';

    std::cout << "Enter R, P, or S:";
    std::cin >> user;

    // displays what the computer
    std::cout << "The computer throws " << computer << std::endl;

    // determines the winner
    if (computer == 'R') { // rock
        if (user == 'R')
            std::cout << "It's a tie!";
        else if (user == 'P')
            std::cout << "You win! Paper covers rock";
        else
            std::cout << "You lose! Rock breaks scissors";
    }
    else if (computer == 'P') { // paper
        if (user == 'R')
            std::cout << "You lose! Paper covers rock";
        else if (user == 'P')
            std::cout << "It's a tie!";
        else
            std::cout << "You win! Scissors cut paper";
    }
    else { // scissors
        if (user == 'R')
            std::cout << "You win! Rock breaks scissors";
        else if (user == 'P')
            std::cout << "You lose! Scissors cut paper";
        else
            std::cout << "It's a tie!";
    }

    return 0;
}
