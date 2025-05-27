/*---------------------------------------------------------
 *    File: HelloWorld.cpp
 *  Author: Darren Fulton
 *   Class: COP 2006 Spring 2022
 * Purpose: Hello World program to familiarize self with IDE
 * ---------------------------------------------------------*/

#include <iostream> 
#include <string>       // create a string variable for my name 

using namespace std;

int main() {

    string myName = "Darren Fulton";

    cout << "Hello, World!" << " my name is " + myName << endl;

    return 0;
}