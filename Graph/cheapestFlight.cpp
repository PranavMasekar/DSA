#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+10;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int ks) {
        vector<int> prices(n,INF);
        prices[src] = 0;
        for(int i=0;i<ks+1;i++){
            vector<int> tempPrices(prices);
            for(auto vec : flights){
                int source = vec[0];
                int destination = vec[1];
                int weight = vec[2];
                if(prices[source]==INF) continue;
                if(prices[source] + weight < tempPrices[destination]){
                    tempPrices[destination] = prices[source] + weight;
                }
            }
            prices = tempPrices;
        }
        if(prices[dst]==INF) return -1;
        else return prices[dst];
    }
};

int main(){
    
    return 0;
}