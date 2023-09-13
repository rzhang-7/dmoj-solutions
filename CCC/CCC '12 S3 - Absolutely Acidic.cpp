#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc12s3

bool cmp(pair<int,int> x, pair<int,int> y){
  return x.second > y.second;
}

int main() {
  int n;
  map<int,int> mii;
  cin>>n;
  for(int i = 0, r; i<n; i++){
    cin>>r;
    mii[r]++;
  }
  vector<pair<int,int>> v;
  for(auto it : mii){
    v.push_back(it);
  }
  sort(v.begin(), v.end(), cmp);
  
  int min = v[0].first, cntr = 1, ans = 0;

  while(v[cntr].second == v[0].second){
    if(ans < abs(v[cntr].first-min)){
      ans = abs(v[cntr].first-min);
    }
    cntr++;
  }
  if(cntr == 1){
    do {
      if(ans < abs(v[cntr].first-min)){
        ans = abs(v[cntr].first-min);
      }
      cntr++;
    } while(v[cntr].second == v[1].second);
  }
  cout<<ans<<"\n";
}