#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    delete[] output;
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

int main()
{
    int arr1[10] = {10, 7, 8, 9, 1, 5, 3, 2, 4, 6};
    int arr2[10] = {20, 17, 18, 19, 11, 15, 13, 12, 14, 16};
    int combined[20];
    for (int i = 0; i < 10; i++)
    {
        combined[i] = arr1[i];
        combined[i + 10] = arr2[i];
    }
    radixSort(combined, 20);
    cout << "Sorted array using Radix Sort: ";
    for (int i = 0; i < 20; i++)
    {
        cout << combined[i] << " ";
    }
    cout << endl;
    return 0;
}
