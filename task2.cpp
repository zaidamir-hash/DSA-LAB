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

void countingSortDesc(int arr[], int n, int exp)
{
    int *output = new int[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 8; i >= 0; i--)
    {
        count[i] += count[i + 1];
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

void radixSortAsc(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);
    }
}

void radixSortDesc(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSortDesc(arr, n, exp);
    }
}

int main()
{
    int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *arrAsc = new int[n];
    for (int i = 0; i < n; i++)
        arrAsc[i] = arr[i];
    radixSortAsc(arrAsc, n);
    cout << "Ascending: ";
    for (int i = 0; i < n; i++)
        cout << arrAsc[i] << " ";
    cout << endl;
    delete[] arrAsc;
    int *arrDesc = new int[n];
    for (int i = 0; i < n; i++)
        arrDesc[i] = arr[i];
    radixSortDesc(arrDesc, n);
    cout << "Descending: ";
    for (int i = 0; i < n; i++)
        cout << arrDesc[i] << " ";
    cout << endl;
    delete[] arrDesc;
    return 0;
}