#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        // If the number is even then it has same number of bits as of its half 
        // if odd then same number for bits as previous + 1
        vector<int> ans(n);
        if(n==0) return ans;

        for(int i=1;i<=n;i++){
            if(i%2==0) ans[i] = ans[i/2];
            else ans[i] = ans[i-1]+1;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}