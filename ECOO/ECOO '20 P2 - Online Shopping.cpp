#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ecoo20p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;cin>>t;
  while(t--){
    int n, k, ans = 0;
    map<string,vector<pair<int,int>>> store;
    vector<pair<string,int>> l;
    cin>>n;
    for(int i = 0, m; i<n; i++){
      cin>>m;
      for(int j = 0, p, q; j<m; j++){
        string s;
        cin>>s>>p>>q;
        store[s].push_back({p,q});
      }
    }
    vector<pair<string,vector<pair<int,int>>>> temp;
    for(auto x : store){
      temp.push_back({x.first,x.second});
      sort(temp[0].second.begin(),temp[0].second.end());
      store[x.first] = temp[0].second;
      temp.clear();
    }
    cin>>k;
    for(int j = 0, d; j<k; j++){
      string s;
      cin>>s>>d;
      l.push_back({s,d});
    }
    // debug
    // for(auto x : store){
    //   cout<<x.first<<" ";
    //   for(auto y : x.second){
    //     cout<<"("<<y.first<<","<<y.second<<"),";
    //   }
    // } return 0;
    
    for(auto x : l){
      for(auto y : store[x.first]){
        if(x.second == 0) break;
        if(x.second >= y.second){
          ans += y.first * y.second;
          x.second -= y.second;
        } else {
          ans += y.first * x.second;
          x.second = 0;
        }
      }
    }
    cout<<ans<<"\n";
  }
}