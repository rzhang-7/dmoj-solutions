#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc14c3p4

const int MM = 1e5+1;

int t, n = -MM, sieve[MM];
vector<int> a[MM];
vector<pair<int,pair<int,int>>> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--){
    int k, a, b; cin>>k>>a>>b;
    n = max(b, n);
    v.push_back({k,{a,b}});
  }
  for(int i = 1; i<=n; i++){
    for(int j = i; j<=n; j+=i){
      sieve[j]++;
    }
  }
  for(int i = 1; i<=n; i++){
    a[sieve[i]].push_back(i); // numbers with the same number of factors are pushed into the same vector
  }
  for(auto x : v){
    cout<<upper_bound(a[x.first].begin(), a[x.first].end(), x.second.second) - lower_bound(a[x.first].begin(), a[x.first].end(), x.second.first)<<"\n";
  }
}