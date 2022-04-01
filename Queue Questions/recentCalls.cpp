#include<bits/stdc++.h>
using namespace std;


// Incomplete
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        if(q.empty()){
            q.push(t);
        }
        else {
            int diff = abs(q.front()-t);
            if(diff>3000){
                int numberOfPops = diff % 3000;
                for(int i=0;i<numberOfPops;i++){
                    if(!q.empty()){
                        q.pop();
                    } 
                }
            }
            q.push(t);
        }
        return q.size();
    }
};

int main(){
    
    return 0;
}