#include<bits/stdc++.h>
using namespace std;

bool isOdd(int n){
    return (n & 1) ==1 ;
}
int main(){
    // To check the number is even or odd we have to check the last bit of the number in binary form
    // If last bit ==1  then number is odd else number is even 
    // To get the last bit of any binary number Just and with 1
    //   1  0  0  0  1
    //   0  0  0  0  1
    // ans :
    //   0  0  0  0  1
    int n = 32;
    cout<<isOdd(n)<<endl;
    return 0;
}