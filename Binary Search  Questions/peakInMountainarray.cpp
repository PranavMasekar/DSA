#include<bits/stdc++.h>
using namespace std;

int Mountain(int arr[],int size){
    int start = 0;
    int end = size-1;
    while(start<end){
        int mid = start + (end - start) / 2;
        if(arr[mid]>arr[mid+1]){
            // Currently present in decreasing part of the array This can be our ans but there can be possible ans at left side.
            end = mid;
        }
        else{
            // Currently in ascending part of the array
            start = mid + 1 ;

        }
    }
    // In the end start , end , mid will point to same position in the array i.e will be the max element in array
    return arr[start];
}

int main(){
    int arr[] = {1,2,3,4,5,10,8,6,2,0};
    int size = 10;
    cout<<Mountain(arr,size)<<endl;
    return 0;
}