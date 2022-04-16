#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    int f,r;
    int size;
    int currentSize;
    vector<int> circularQueue;
    MyCircularQueue(int k) {
        circularQueue = vector<int>(k,0);
        f = r = 0;
        size = k;
        currentSize = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        else {
            circularQueue[r] = value;
            r = (r + 1) % size;
            currentSize++;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        else {
            f = (f + 1) % size;
            currentSize--;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()) return -1;
        else return circularQueue[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else return circularQueue[(r + size - 1)% size];
    }
    
    bool isEmpty() {
        if(currentSize==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(currentSize==size) return true;
        else return false;
    }
};

int main(){
    
    return 0;
}