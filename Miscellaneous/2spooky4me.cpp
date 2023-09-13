#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/2spooky4me

// simulates kenny walking down the neighbourhood (kind of)
// thus the distances are sorted in increasing order
// when he finds the spooky decorations, the spookiness increases.
// when the spooky decoration ends, then the spookiness decreases
// the ends have a distance incremented by 1 to account to be inclusive
// if the cumulative spookiness is too high, then he cannot travel until the spookiness drops

int n, l, s;
vector<pair<int,int>> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>l>>s;
  v.push_back({l+1, 0});
  for(int i = 0, a, b, s; i<n; i++){
    cin>>a>>b>>s;
    v.push_back({a, s});
    v.push_back({b + 1, -s});
  }
  sort(v.begin(), v.end());
  int cur = 0;
  for(int i = 0; i<(int)v.size()-1; i++){
    cur += v[i].second;
    if(cur >= s){
      l -= (v[i+1].first - v[i].first);
    }
  }
  cout<<l<<"\n";
}
// v ={{3, 2}, {5, 2}, {6, -2}, {8, -2}, {11, 0}}

// v = {{101, 0}, {20, 4}, {60, -4}, {30, 4}, {70, -4}, {40, 4}, {80, -4}}
// v = {{20, 4}, {30, 4}, {40, 4}, {60, -4}, {70, -4}, {80, -4}, {101, 0}}