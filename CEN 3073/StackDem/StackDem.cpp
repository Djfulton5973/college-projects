#include "Stack.cpp"

// --------------------------------------------------------
// Function Prototypes
// --------------------------------------------------------
void enterName(int,Stack &);
void nameBack(int,Stack &);

// --------------------------------------------------------
// Main Function
// --------------------------------------------------------
int main() {

    Stack newStack;

    std::cout << "How many letters are in your last name? \n ->";

    int num;
    std::cin >> num;

    // The name has the letters printed out, one by one
    enterName(num,newStack);

    std::cout << "Now the name backwards." << std::endl;

    // The stack is referenced and the top element is printed and popped, one by one
    nameBack(num,newStack);

    return 0;
}

// --------------------------------------------------------
// Function Definitions
// --------------------------------------------------------
void enterName(int n, Stack &array){

    char letter;

    for (int i = 0; i < n; ++i) {

        std::cout << "Enter a letter. \n ->";
        std::cin >> letter;

        array.push(letter);
        std::cout << array.peek() << std::endl;

    }

}

void nameBack(int nub, Stack &larry) {

    for (int k = 0; k < nub; ++k) {

        std::cout << larry.peek() << std::endl;
        larry.pop();

    }

}