#include <iostream>;

int main() {

	int index = 0;
	char letters[4] = { 'F', 'G', 'C', 'U' };

	std::cout << letters[index] << endl;
	index++;
	std::cout << letters[index] << endl;

	char* ptrArray;
	ptrArray = &letters[0];

	std::cout << std::hex; // forma output of numbers as hex

	std::cout << int(ptrArray) << std::endl;
	std::cout << ptrArray << std::endl;

	ptrArray++;




	return 0;
}