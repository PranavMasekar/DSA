#include<bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:

    vector<int> queue;
	
    FrontMiddleBackQueue(){
	}
    
    void pushFront(int val){
        queue.insert(queue.begin(),val);
    }
    
    void pushMiddle(int val){
        int middle;
        middle = queue.size()/2;
        queue.insert(queue.begin()+middle,val);
    }
    
    void pushBack(int val){
        queue.push_back(val);
    }
    
    int popFront(){
        if(queue.size() == 0)
            return -1;
        
        int val = queue[0];
        queue.erase(queue.begin());
        return val;
    }
    
    int popMiddle(){
        if(queue.size() == 0)
            return -1;
        
		int middle= (queue.size()%2 == 0) ? (queue.size()/2)-1 : queue.size()/2;
        
		int val = queue[middle];
        queue.erase(queue.begin()+middle);
        return val;
    }
    
    int popBack(){
        if(queue.size() == 0)
            return -1;
        
        int val = queue.back();
        queue.pop_back();
        return val;
    }
    
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main(){
    
    return 0;
}