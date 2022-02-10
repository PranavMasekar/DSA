#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 6;
    int ans = 0;
    int base = 5;
    while(n>0){
        // We get the last bit of binary then multiply with the base and then add to the ans 
        int lastBit = n & 1;
        // After we get the lastbit we shift the number by using right shift operator
        n = n >> 1;
        ans += lastBit* base;
        base *=5;
    }
    cout<<ans<<endl;

    // To get the number of bits in number
    n = 3456;
    int b = 10;
    int bits = (int)(log(n)/log(b)) + 1;
    cout<<bits<<endl;
    return 0;
}

// Number of bits in base b
// No of digits in binary of base b = int(log n to base b ) + 1