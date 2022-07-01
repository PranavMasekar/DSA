#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int> arr,int i,int j){
    if(i>=j) return 0;
    int minimum = INT_MAX;
    for(int k=i;k<j;k++){
        int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1] * arr[k]* arr[j];
        if(temp<minimum) minimum = temp;
    }
    return minimum;
}

int main(){
    vector<int> arr = {10, 20, 30};
    cout<<MCM(arr,1,arr.size()-1)<<endl;
    return 0;
}