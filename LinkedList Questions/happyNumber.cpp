#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findSquare(int n){
        int ans = 0;
        while(n>0){
            int remainder = n % 10;
            n = n / 10;
            ans += remainder * remainder;
        }
        return ans;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        }while(fast!=slow);
        if(slow==1) return true;
        else return false;
    }
};

int main(){
    
    return 0;
}