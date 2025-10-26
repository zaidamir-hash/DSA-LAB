#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

void swapElements(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partitionFirst(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1, j = high;
    while(true){
        while(i <= high && arr[i] <= pivot){ comparisons++; i++; }
        while(j >= low && arr[j] > pivot){ comparisons++; j--; }
        if(i < j) swapElements(arr[i], arr[j]);
        else break;
    }
    swapElements(arr[low], arr[j]);
    return j;
}

int partitionRandom(int arr[], int low, int high){
    int pivotIndex = low + rand() % (high - low + 1);
    swapElements(arr[low], arr[pivotIndex]);
    return partitionFirst(arr, low, high);
}

int partitionMiddle(int arr[], int low, int high){
    int mid = (low + high) / 2;
    swapElements(arr[low], arr[mid]);
    return partitionFirst(arr, low, high);
}

int medianOfThree(int arr[], int low, int high){
    int mid = (low + high) / 2;
    int a = arr[low], b = arr[mid], c = arr[high];
    if((a > b) != (a > c)) return low;
    else if((b > a) != (b > c)) return mid;
    else return high;
}

int partitionMedian(int arr[], int low, int high){
    int pivotIndex = medianOfThree(arr, low, high);
    swapElements(arr[low], arr[pivotIndex]);
    return partitionFirst(arr, low, high);
}

void quickSort(int arr[], int low, int high, int type){
    if(low < high){
        int p;
        if(type == 1) p = partitionFirst(arr, low, high);
        else if(type == 2) p = partitionRandom(arr, low, high);
        else if(type == 3) p = partitionMiddle(arr, low, high);
        else p = partitionMedian(arr, low, high);
        quickSort(arr, low, p - 1, type);
        quickSort(arr, p + 1, high, type);
    }
}

void copyArray(int src[], int dest[], int n){
    for(int i = 0; i < n; i++) dest[i] = src[i];
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main(){
    srand(time(0));
    const int n = 10;
    int sorted[n], reverseSorted[n], randomArr[n], arr[n];

    for(int i = 0; i < n; i++){
        sorted[i] = i + 1;
        reverseSorted[i] = n - i;
        randomArr[i] = rand() % 100;
    }

    cout << "Sorted Array:\n";
    printArray(sorted, n);
    cout << "Reverse Sorted Array:\n";
    printArray(reverseSorted, n);
    cout << "Random Array:\n";
    printArray(randomArr, n);

    int types[4] = {1, 2, 3, 4};
    const char* names[4] = {"First Element", "Random Element", "Middle Element", "Median of Three"};

    for(int t = 0; t < 4; t++){
        cout << "\n--- " << names[t] << " Pivot ---\n";

        copyArray(sorted, arr, n);
        comparisons = 0;
        quickSort(arr, 0, n - 1, types[t]);
        cout << "Sorted array comparisons: " << comparisons << endl;

        copyArray(reverseSorted, arr, n);
        comparisons = 0;
        quickSort(arr, 0, n - 1, types[t]);
        cout << "Reverse sorted comparisons: " << comparisons << endl;

        copyArray(randomArr, arr, n);
        comparisons = 0;
        quickSort(arr, 0, n - 1, types[t]);
        cout << "Random array comparisons: " << comparisons << endl;
    }

    return 0;
}
