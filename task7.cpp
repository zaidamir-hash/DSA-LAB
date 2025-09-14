#include <iostream>
#include <string>
using namespace std;

int linearSearch(string arr[], int n, string key, int &steps) {
    steps = 0;
    for (int i = 0; i < n; i++) {
        steps++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(string arr[], int n, string key, int &steps) {
    int low = 0, high = n - 1;
    steps = 0;
    while (low <= high) {
        steps++;
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    int n = 10;
    string keys[] = {"Aftab", "Rizwan", "Tariq"};
    for (int k = 0; k < 3; k++) {
        int stepsLin, stepsBin;
        int idxLin = linearSearch(arr, n, keys[k], stepsLin);
        int idxBin = binarySearch(arr, n, keys[k], stepsBin);
        cout << "Key: " << keys[k] << endl;
        cout << "Linear Search -> Index: " << idxLin << ", Steps: " << stepsLin << endl;
        cout << "Binary Search -> Index: " << idxBin << ", Steps: " << stepsBin << endl;
        cout << endl;
    }
}
