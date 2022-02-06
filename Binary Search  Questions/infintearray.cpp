#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[],int element,int low,int high)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int findRange(int arr[] , int element){
    // Doubling the range of the accessible array
    int start = 0;
    int end = 1;
    while(element>arr[end]){
        int newstart = end+1;
        end = (end - start)*2 + end;
        start = newstart;
    }
    return binarysearch(arr,element,start,end);
}

int main(){
    int arr[] = {1,2,2,2,5,6,6,6};
    cout<<findRange(arr,5)<<endl;
    return 0;
}