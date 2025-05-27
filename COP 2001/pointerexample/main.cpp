#include <iostream>

int sumOfShorts(short *pShorts);

int main() {

    int myInt = 10;
    char myChar = 'L';
    double myDouble = 35.25;
    short shortArray[] = {365, 25, 0, 270};

    short *pShort = &shortArray[0]; //pointer is the size of the address

    int sum = sumOfShorts(pShort);

    return 0;
}

int sumOfShorts(short *pShorts) {

    int sum = 0;
    for(int i = 0; i < 5; i++) {

        sum += *pShorts;
        pShorts++;// 1 times the size of the data type. EX: pShort++ means 1 * short(2 bytes), equaling 2

    }

    return sum;
}