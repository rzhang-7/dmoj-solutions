#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/wc18c3j4

int n, s, l;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>s>>l;
  map<int, pair<int,int>> mp;
  vector<int> v;
  for(int i = 1, p, m, g; i<=n; i++){
    cin>>p>>m>>g;
    mp[p] = {m,g};
    v.push_back(p);
  }
  sort(v.begin(), v.end());
  int rit = lower_bound(v.begin(), v.end(), s) - v.begin();
  int lft = rit-1;
  // for(int i = 0; i<n; i++){
  //   cout<<v[i]<<" \n"[i==n-1];
  // }
  // cout<<"rit: "<<rit<<"\nlft: "<<lft<<"\n\n";
  bool stuck = false;
  while((rit < n || lft >= 0) && !stuck){
    stuck = true;
    if(rit < n && mp[v[rit]].first <= l){
      l += mp[v[rit]].second;
      rit++;
      stuck = false;
      // cout<<"rit: "<<rit<<"\n";
    }
    if(lft >= 0 && mp[v[lft]].first <= l){
      l += mp[v[lft]].second;
      lft--;
      stuck = false;
      // cout<<"lft: "<<lft<<"\n";
    }
    // cout<<l<<"\n";
  }
  cout<<l<<"\n";
}