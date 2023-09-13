#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ccc10s1

bool cmp(pair<string,int> x, pair<string,int> y){
  return x.second > y.second;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, r, s, d;
  string name;
  vector<pair<string,int>> vpi;
  map<string,int> msi;
  cin>>n;
  if(n){
    for(int i = 0; i<n; i++){
      cin>>name>>r>>s>>d;
      msi[name] = 2*r + 3*s + d;
    }
    for(auto x : msi){
      vpi.push_back(x);
    }
    sort(vpi.begin(), vpi.end(), cmp);
    
    cout<<vpi[0].first<<"\n"<<vpi[1].first<<"\n";
  }
}