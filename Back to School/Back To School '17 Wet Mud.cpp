#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/bts17p4

int n, m, j, ans;

bool cmp(pair<int,int> x, pair<int,int> y){
  return x.second < y.second || (x.second == y.second && x.first > y.first);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>j;
  vector<int> v(n+1, -1);
  for(int i = 0, p, t; i<m; i++){
    cin>>p>>t;
    v[p] = t;
  }
  v[n+1] = 0;
  int pos = 0;
  while(pos <= n){
    vector<pair<int,int>> vp;
    for(int i = pos+j; i > pos; i--){
      if(v[i] != -1) vp.push_back({i, v[i]});
    }
    sort(vp.begin(), vp.end(), cmp);
    if(vp.empty()) break;
    ans = max(ans, vp[0].second);
    pos = vp[0].first;
  }
  cout<<(pos < n ? -1 : ans)<<"\n";
}