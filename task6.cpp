#include <iostream>
using namespace std;


int recursiveArraySum(int** arr, int rows, int cols) {
    if (rows == 0) return 0; 
    if (cols == 0) return 0; 
    
    int sumRow = 0;
    for (int j = 0; j < cols; j++) {
        sumRow += arr[0][j];
    }

    
    return sumRow + recursiveArraySum(arr + 1, rows - 1, cols);
}

int main() {
    int a1[] = {1, 2};
    int a2[] = {3, 4};
    int* arr[] = {a1, a2};

    int rows = 2, cols = 2;

    cout << "Sum = " << recursiveArraySum(arr, rows, cols) << endl;
    return 0;
}
