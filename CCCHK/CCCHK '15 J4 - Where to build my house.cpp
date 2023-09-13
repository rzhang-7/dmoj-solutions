#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/hkccc15j4

int len, n, pos, ans;
vector<pair<int,int>> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>len>>n;
  for(int i = 0, l, r; i<n; i++){
    cin>>l>>r;
    v.push_back({l,r});
  }
  sort(v.begin(), v.end());
  for(auto x : v){
    int st = x.first, ed = x.second;
    if(st > pos) ans = max(ans, st-pos);
    pos = max(pos, ed);
  }
  ans = max(ans, len - pos);
  cout<<ans<<"\n";
}