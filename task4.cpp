#include <iostream>
using namespace std;

bool hasDuplicate(int arr[], int n) {
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]) return true;
        }
    }
    return false;
}

int main() {
    int arr[]={1,2,3,4,2};
    int n=5;
    cout<<"Array contains duplicates? "<<(hasDuplicate(arr,n)?"Yes":"No");
}
