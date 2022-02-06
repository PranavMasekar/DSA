#include<bits/stdc++.h>
using namespace std;
int CeilingOfNumber(int arr[], int size, int element)
{
    int low, mid, high;

    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return arr[mid];
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return arr[low];
}


int main(){
    int arr[] = {1,5,8,6,9};
    cout<<CeilingOfNumber(arr,5,2)<<endl;
    return 0;
}