#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/casinocrisis

int n, q;
vector<int> v;
vector<pair<int,int>> ans;

void f(int l, int r){
  if(l >= r) return;
  reverse(v.begin()+l, v.begin()+r+1);
  ans.push_back({l+1, r+1});
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  v.resize(n);
  for(int i = 0; i<n; i++){
    cin>>v[i];
  }
  for(int i = 1; i<n; i++){
    if(v[i] < v[i-1]){
      int idx = upper_bound(v.begin(), v.begin()+i, v[i]) - v.begin();
      f(idx, i-1); f(idx, i);
    }
  }
  cout<<ans.size()<<"\n";
  for(auto x : ans){
    cout<<x.first<<" "<<x.second<<"\n";
  }
}