/*---------------------------------------------------------
 *    File: descend.cpp
 *  Author: Darren Fulton
 *   Class: COP 2006 Spring 2022
 * Purpose: Takes user input & puts three integers in descending order
 * ---------------------------------------------------------*/

#include <iostream>

using namespace std;

int main() {

	int variableOne;
	int variableTwo;
	int variableThree;

	cout << "Enter an integer for the first variable: ";
	cin >> variableOne;

	cout << "Enter an integer for the second variable: ";
	cin >> variableTwo;

	cout << "Enter an integer for the third variable: ";
	cin >> variableThree;

	if (variableOne > variableTwo && variableOne > variableThree) {
		cout << "In descending order: " << variableOne << ", ";
		
		if (variableTwo > variableThree) {
			cout << variableTwo << ", and " << variableThree;

		}
		else {
			cout << variableThree << ", and " << variableTwo;

		}

	}
	else if (variableTwo > variableThree) {
		cout << "In descending order: " << variableTwo << ", ";

		if (variableOne > variableThree) {
			cout << variableOne << ", and " << variableThree;

		}
		else {
			cout << variableThree << ", and " << variableOne;

		}

	}
	else {
		cout << "In descending order: " << variableThree << ", ";

		if (variableOne > variableTwo) {
			cout << variableOne << ", and " << variableTwo;

		}
		else {
			cout << variableTwo << ", and " << variableOne;

		}
	}

	return 0;
}