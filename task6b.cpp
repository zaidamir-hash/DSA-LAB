#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(combined, 0, 19);
    cout << "Sorted array using Merge Sort: ";
    for (int i = 0; i < 20; i++)
    {
        cout << combined[i] << " ";
    }
    cout << endl;
    return 0;
}
