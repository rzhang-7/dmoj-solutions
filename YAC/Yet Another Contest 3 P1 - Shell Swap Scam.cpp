#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/yac3p1

// https://github.com/AAZZAZRON/DMOJ-Solutions/blob/main/yac3p1.py

int n, m, a, b, first = -1;
vector<pair<int,int>> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>a>>b;
  for(int i = 0, x, y; i<m; i++){
    cin>>x;
    if(x == -1 && first == -1)
      first = i;
    if(x == -1)
      v.push_back({1,2});
    else{
      cin>>y;
      v.push_back({x,y});
    }
  }
  for(int i = 0; i<first; i++){
    if(v[i].first == a)
      a = v[i].second;
    else if(v[i].second == a)
      a = v[i].first;
  }
  for(int i = m-1; i>first; i--){
    if(v[i].first == b)
      b = v[i].second;
    else if(v[i].second == b)
      b = v[i].first;
  }
  if(a != b)
    v[first] = {a,b};
  else {
    v[first] = {(a-1>=1 ? a-1 : n),(a+1<=n ? a+1 : 1)};
  }
  for(auto x : v)
    cout<<x.first<<" "<<x.second<<"\n";
}