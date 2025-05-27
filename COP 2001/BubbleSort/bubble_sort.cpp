/**
 *  file: bubble_sort.cpp
 *    by: Darren Fulton
 * class: COP 2001, Summer-B, 2022
 *  desc: This program implements a bubble sort algorithm to sort
 *        a list of integers using pointers to swap values in the
 *        array and print the list to the console.
 *
 * From Wikipedia: https://en.wikipedia.org/wiki/Bubble_sort
 *
 * Bubble sort, sometimes referred to as sinking sort, is a simple
 * sorting algorithm that repeatedly steps through the list, compares
 * adjacent elements and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * The algorithm, which is a comparison sort, is named for the way
 * smaller or larger elements "bubble" to the top of the list.
 *
 * Step-by-step example:
 *
 * Take an array of numbers "5 1 4 2 8", and sort the array from lowest
 * number to greatest number using bubble sort. In each step, elements
 * written in brackets [ ] are being compared. Three passes will be required;
 *
 * First Pass
 *      ([5 1]4 2 8 ) → ([1 5]4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
 *      ( 1[5 4]2 8 ) → ( 1[4 5]2 8 ), Swap since 5 > 4
 *      ( 1 4[5 2]8 ) → ( 1 4[2 5]8 ), Swap since 5 > 2
 *      ( 1 4 2[5]8 ) → ( 1 4 2[5 8]), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
 *  Second Pass
 *      ([1 4]2 5 8 ) → ([1 4]2 5 8 )
 *      ( 1[4 2]5 8 ) → ( 1[2 4]5 8 ), Swap since 4 > 2
 *      ( 1 2[4 5]8 ) → ( 1 2[4 5]8 )
 *      ( 1 2 4[5 8]) → ( 1 2 4[5 8])
 *
 *  Now, the array is already sorted, but the algorithm does not know if it is completed.
 *  The algorithm needs one additional whole pass without any swap to know it is sorted.
 *
 *  Third Pass
 *      ([1 2]4 5 8 ) → ([1 2]4 5 8 )
 *      ( 1[2 4]5 8 ) → ( 1[2 4]5 8 )
 *      ( 1 2[4 5]8 ) → ( 1 2[4 5]8 )
 *      ( 1 2 4[5 8]) → ( 1 2 4[5 8])
 *
 ********************************************************************/
#include <iostream>

// Function Declarations (prototypes)
// --------------------------------------------------------
void swap(int *pOne, int *pTwo);   //*** declare integer pointer params p1 and p2
void printArray(int *pArray, int arrayLen); //*** declare integer pointer param pArray

/**
 * Main executable function.
 * @return An Integer representing program completion status (0=SUCCESS).
 */
int main() {

    // initialize a list of integers
    int array[] = {7, 18, 3, 15, 6, 4, 27, 1};
    // set the length of the array
    int arrayLen = 8;

    bool moved; // determine if any elements have been swapped in the array each pass
    do {
        moved = false; // reset moved to false for each pass

        // output the current state of the list        
        printArray(&array[0], arrayLen); //*** pass a reference to 1st element in array to pArray

        // walk the list from head to element before the tail
        // comparing overlapping pairs of values
        for (int i = 0; i < arrayLen - 1; i++) {

            // compare current array element with the next element in the array
            if (array[i] > array[i + 1]) {

                // swap them if current > next
                swap(&array[i], &array[i + 1]); //*** pass references to current and next array elements to p1, p2

                // update moved for this pass
                moved = true;
            } // compare elements

        } // for each

    } while (moved); // keep going through list until no elements are moved


    return 0;  // return success to OS
} // end main


/**
 * Swap to integer values in memory.
 * @param p1 An integer pointer to the first value.
 * @param p2 An integer pointer to the second value.
 */
void swap(int *pOne, int *pTwo) { //*** declare integer pointer params p1 and p2

    int tmp = *pOne; //*** copy value in p1 to tmp

    // swap the values in the pointers
    *pOne = *pTwo;   //*** copy value in p2 to p1
    *pTwo = tmp;   //*** copy value in tmp to p2

} // end swap


/**
 * Print the values in an integer array on the console.
 * @param pArray A pointer to the 1st element of an integer array.
 * @param arrayLen The length of the array.
 */
void printArray(int *pArray, int arrayLen) { //*** declare integer pointer param pArray

    // walk through the array from head to tail
    // printing each integer
    for (int i = 0; i < arrayLen; i++) {

        // send the value in the pointer to the console
        std::cout << *pArray; //*** output value in pArray

        // add a comma if not the last array element
        if (i < arrayLen - 1)
            std::cout << ",";

        // increment the array pointer
        pArray++; //*** increment pArray
    }
    // add an end-line
    std::cout << std::endl;

} // end printArray