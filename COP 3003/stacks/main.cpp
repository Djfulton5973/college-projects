#include <iostream>
#include <stack>

void showElements(std::stack <int> st);
void isEmpty(std::stack <int> st);

int main() {

    std::stack <int> numbers;

    numbers.push(2);
    numbers.push(9);

    showElements(numbers);

    std::cout << "\nSize of the stack: " << numbers.size() << std::endl;

    std::cout << "Top of the stack: " << numbers.top() << std::endl;

    std::cout << "\nRemoving one element from the stack..." << std::endl;

    numbers.pop();

    isEmpty(numbers);

    std::cout << "Removing the remaining element from the stack..." << std::endl;

    numbers.pop();

    isEmpty(numbers);

    return 0;
}

void showElements(std::stack <int> st) {

    std::cout << "\nElement(s) placed in stack:\n";

    while(!st.empty()) {

        std::cout << st.top() << std::endl;
        st.pop();

    }

}

void isEmpty(std::stack <int> st) {

    if (st.empty())
        std::cout << "The stack is empty." << std::endl;
    else
        std::cout << "The stack is not empty." << std::endl;

}