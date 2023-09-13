#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc04s2

int n, k, mx = -1001, y[101], worst[101];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
    
  for(int i = 0; i<k; i++){
    vector<int> temp;
    set<int> s;
    for(int j = 1, x; j<=n; j++){
      cin>>x;
      y[j] += x;      
    }
    for(int j = 1; j<=n; j++){
      s.insert(y[j]);
    } 
    for(int x : s){
      temp.push_back(x);
    }
    for(int j = 1; j<=n; j++){    
      worst[j] = max(worst[j], (int)temp.size()+1-(int) (upper_bound(temp.begin(), temp.end(), y[j])-temp.begin()));
    }
  }
  for(int i = 1; i<=n; i++){
    mx = max(mx, y[i]);
  }
  for(int i = 1; i<=n; i++){
    if(y[i] == mx){
      cout<<"Yodeller "<<i<<" is the TopYodeller: score "<<y[i]<<", worst rank "<<worst[i]<<"\n";
    }
  }
}