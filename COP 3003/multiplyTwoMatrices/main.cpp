#include <iostream>

int main() {

    // two matrices
    int m1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int m2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // the matrices used as the results
    int m3[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // the multiplication of the matrices
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++)
                m3[i][j] += m1[i][k] * m2[k][j];
        }

    std::cout << "\nThe product of the two matrices:" << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << m3[i][j] << "      ";
        }
        std::cout << std::endl;
    }


    return 0;
}
