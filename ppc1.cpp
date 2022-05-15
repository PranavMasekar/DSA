#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> vec(n);
  for(int i = 0; i < n; ++i) cin >> vec[i];

  vector<int> order(vec.size());
  iota(order.begin(), order.end(), 0);
  
  sort(order.begin(), order.end(), [&](int i, int j) {
      return vec[i] < vec[j];
  });

  for(int n: order) cout << n << " ";
  
  int ans = 0;
  int maximum = -1;
  
  for(int i = 0; i < n; ++i) {
      if(maximum < i) {
          ans++;
      }
      maximum = max(maximum, order[i]);
  }

  cout << ans;

  return 0;
}

