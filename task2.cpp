#include <iostream>
using namespace std;

int main() {
    int arr[9]={20,12,15,2,10,1,13,9,5};
    int n=9;
    for(int i=1;i<n;i++){
        int key=arr[i],j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    int maxIndex=0;
    for(int i=1;i<n;i++) if(arr[i]>arr[maxIndex]) maxIndex=i;
    int maxVal=arr[maxIndex];
    for(int i=maxIndex;i<n-1;i++) arr[i]=arr[i+1];
    for(int i=n-1;i>n/2;i--) arr[i]=arr[i-1];
    arr[n/2]=maxVal;
    cout<<"Sorted with max in middle: ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
