#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *arr , int curr , int next , int size){
    if(curr==size) return true;
    if(arr[curr]>arr[next]) return false;
    else return isSorted(arr,curr+1,next+1,size);
}

int main(){
    int arr[50] = {1,2,3,6,8};
    cout<<isSorted(arr,0,1,4);
    return 0;
}