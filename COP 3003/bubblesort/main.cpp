#include <iostream>

void bubbleSort(int list[], int n);
void printArray(int list[], int size);

int main() {

    int myArray[] = {15, 25, 19,18,30,50};
    int n = sizeof(myArray) / sizeof(myArray[0]);

    bubbleSort(myArray, n);
    printArray(myArray, n);

    return 0;
}

void bubbleSort(int list[], int n) {

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (list[j] > list[j + 1])

                std::swap(list[j], list[j + 1]);

        }
    }

}

void printArray(int list[], int size) {

    for (int i = 0; i < size; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");

}