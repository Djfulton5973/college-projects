#include <iostream>

int main() {

    int arr[][3] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

    int n = sizeof(arr)/ sizeof(arr[0]);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }

    }

    for (int l = 0; l < n; ++l) {
        for (int k = 0; k < n/2; ++k) {
            int tmp = arr[l][k];
            arr[l][k] = arr[l][n-k-1];
            arr[l][n-k-1] = tmp;
        }

    }

    for (int p = 0; p < n; ++p) {
        for (int u = 0; u < n; ++u) {
            std::cout << arr[p][u] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
