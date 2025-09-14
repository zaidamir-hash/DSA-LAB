#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {23, 1, 45, 34, 7, 5, 15, 67, 99, 21};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 13;
    bool found = false;
    for (int i = 0; i < n; i++) if (arr[i] == key) found = true;
    if (!found) {
        int newArr[11];
        for (int i = 0; i < n; i++) newArr[i] = arr[i];
        newArr[n] = key;
        n++;
        sort(newArr, newArr + n);
        int idx = binarySearch(newArr, n, key);
        cout << "Found " << key << " at index " << idx << endl;
    } else {
        sort(arr, arr + n);
        int idx = binarySearch(arr, n, key);
        cout << "Found " << key << " at index " << idx << endl;
    }
}
