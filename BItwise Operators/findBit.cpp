#include<bits/stdc++.h>
using namespace std;

int main(){
    // To find the bit ar particular index we just have to do same thing that we did in even odd
    // 1 1 1 1 1 1 0 0 0 0 0 
    // To find the 4th bit from the left just make such number whose 4th bit is 1 and else are 0 
    // Then just and two numbers
    // 1 1 1 1 1 1 0 0 0 0 0 
    // 0 0 0 0 0 0 0 1 0 0 0
    // so this will give us the 4th bit 
    // To find the second number i.e ( 1 0 0 0 ) this second number is known as mask
    // We can do this by using left shift so 
    // left shift 1 by ( m-1 ) times to get the desire number
    // 1 < < 3 in this case
    // 1 0 0 0 
    // so the end formula becomes n & (1 < < ( m - 1 ))
    int n = 64;
    int m = 5;
    int ans = n & (1 << ( m - 1 ));
    cout<<ans<<endl;
    return 0;
}