#include <bits/stdc++.h>
using namespace std;

void bubblesort(int *arr,int r,int c){
    if(r==0){
        return;
    }
    if(c<r){
        if(arr[c]>arr[c+1]){
            swap(arr[c],arr[c+1]);
        }
        bubblesort(arr , r , c+1);
    }
    else bubblesort(arr,r-1,0);
}

int main(){
    int arr[5] = {2,5,1,6,4};
    bubblesort(arr,5,0);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}
