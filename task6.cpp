#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
    int sum = 0;
    if (dim == 1) {
        for (int i = 0; i < sizes[0]; i++) {
            sum += arr[i][0];
        }
    } else {
        for (int i = 0; i < sizes[dim - 1]; i++) {
            sum += recursiveArraySum((int**)arr[i], sizes, dim - 1);
        }
    }
    return sum;
}

int main() {
    int a1[] = {1, 2};
    int a2[] = {3, 4};
    int* arr[] = {a1, a2};
    int sizes[] = {2, 2};
    cout << recursiveArraySum((int**)arr, sizes, 2) << endl;
    return 0;
}
