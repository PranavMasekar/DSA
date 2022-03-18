#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = sizeOfStack / 2;
        stack<int> temp;
        for(int i=0;i<mid;i++){
            temp.push(s.top());
            s.pop();
        }
        s.pop();
        for(int i=0;i<mid;i++){
           s.push(temp.top());
           temp.pop();
        }
    }
};

int main(){
    
    return 0;
}