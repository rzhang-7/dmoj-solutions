#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc17s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  vector<int> rec, low, high;
  cin>>n;
  for(int i = 0,x; i<n; i++){
    cin>>x;
    rec.push_back(x);
  }
  sort(rec.begin(), rec.end());
  copy(rec.begin(), rec.begin() + n/2 + n%2, back_inserter(low));
  copy(rec.begin() + n/2 + n%2, rec.end(), back_inserter(high));
  sort(low.begin(), low.end(), greater<int>());
  
  for(int i = 0; i<n/2 + n%2; i++){
    cout<<low[i]<<" ";
    if(i != n/2) cout<<high[i]<<" ";
    else cout<<" ";
  }
  cout<<"\n";
}