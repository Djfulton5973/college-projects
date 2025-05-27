#include <iostream>
#include <fstream>
#include <string>

int main() {

    std::string words = "Do at least a push up.";

    std::fstream testfile;
    testfile.open("exercise.txt", std::ios::out);
    testfile << words;
    testfile.close();

    testfile.open("exercise.txt", std::ios::in);

    while(!testfile.eof()) {

        std::string str;
        testfile >> str;
        std::cout << str << " ";

    }

    testfile.close();


    return 0;
}
