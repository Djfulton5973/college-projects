#include <iostream>
#include <bits/stdc++.h>

double findMedian(int list[], int n);

int main() {

    int myArray[] = {25, 90, 30, 60, 50, 50};
    int n = sizeof(myArray) / sizeof(myArray[0]);

    std::cout << "The median is " << findMedian(myArray, n);

    return 0;
}

double findMedian(int list[], int n) {

    std::sort(list, list + n);

    if (n % 2 != 0)
        return (double)list[n / 2];
    else
        return (double)(list[(n - 1) / 2] + list[n / 2]) / 2.0;


}