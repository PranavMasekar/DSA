#include <bits/stdc++.h>
using namespace std;

class CustomStack {
    public:
        vector<int> stack;
        int index = -1;
        int size;
        CustomStack(int maxSize) {
            stack.resize(maxSize);
            size = maxSize;
        }

        void push(int x) {
            // Add check for max size of stack
            if(index+1>=size) return ;
            stack[index] = x;
            index++;
        }

        int pop() {
            if(index==-1) return -1;
            int val = stack[index];
            stack[index] = 0;
            index--;
            return val;
        }

        void increment(int k, int val) {
            for(int i=0;i<min(k,index+1);i++){
                stack[i] += val;
            }
        }
};

int main() {

    return 0;
}