#include <bits/stdc++.h>
using namespace std;


int binarysearch(int arr[], int size, int element, bool isStart)
{
    int low, mid, high;
    int ans = -1;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            ans = mid;
            isStart ? high = mid - 1 : low = mid + 1;
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

    return ans;
}

vector<int> FirstAndLastOccurance(int arr[], int size, int element){

    vector<int> ans(2);
    ans[0]=ans[1] = -1;
    int start  = binarysearch(arr,size,element,true);
    int last = binarysearch(arr,size,element,false);
    ans[0] = start;
    ans[1] = last;
    return ans;
}
int main()
{
    int arr[] = {1,2,2,2,5,6,6,6};
    vector<int> ans(2);
    ans = FirstAndLastOccurance(arr,8,6);
    cout<<ans[0]<<endl<<ans[1]<<endl;
    return 0;
}