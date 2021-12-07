#include <bits/stdc++.h>
using namespace std;

void selectionsort(int *arr , int r , int c,int max){
    if(r==0){
        return ;
    }
    if(c<r){
        if(arr[c]>arr[max]){
        selectionsort(arr,r,c+1,c);
        }
        else{

        selectionsort(arr,r,c+1,max);
        }
    }
    else{
        swap(arr[max],arr[r-1]);
        selectionsort(arr,r-1,0,0);

        }
}

int main(){
     int arr[5] = {2,5,1,6,4};
    selectionsort(arr,5,0,0);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}