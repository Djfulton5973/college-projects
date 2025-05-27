#include <iostream>

class Student {
public:

    int number;

};

int main() {

    Student s1, s2;

    //the pointer
    Student *s_ptr;

    //assign the pointer the address of the first object
    s_ptr = &s1;

    //assigns the object s1 a value
    s_ptr->number = 5;

    //the value of s1 is displayed
    std::cout << "The first number the pointer has: " << s_ptr->number << std::endl;

    //assign the pointer the address of the second object
    s_ptr = &s2;

    //assign the object s2 a value
    s_ptr->number = 9;

    //the value of s2 is displayed
    std::cout << "The second number the pointer has: " << s_ptr->number << std::endl;

    //displays the values of the objects without the pointer
    std::cout << "The numbers of s1 and s2: " << s1.number << ", " << s2.number << std::endl;


    return 0;
}
