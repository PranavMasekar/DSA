#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> count_a(n,0);
        vector<int> count_b(n,0);
        int a = 0 , b = 0;
        for(int i=0;i<n;i++){
            count_b[i] = b;
            if(s[i]=='b') b++; 
        }
        for(int i = n-1;i>=0;--i){
            count_a[i] = a;
            if(s[i]=='a') a++;
        }
        int ans = n;
        for(int i=0;i<n;i++) {
         ans = min(ans,count_a[i] + count_b[i]);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}