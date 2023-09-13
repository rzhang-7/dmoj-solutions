#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/usaco19decbronze1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int k, n, ans = 0;
  cin>>k>>n;
  int arr[k][n];
  map<pair<int,int>,int> mpii;
  for(int i = 0; i<k; i++){
    for(int j = 0; j<n; j++){
      cin>>arr[i][j];
    }
  }
  for(int a = 0; a<k; a++){
    for(int i = 0; i<n; i++){
      for(int j = i+1; j<n; j++){
        mpii[make_pair(arr[a][i],arr[a][j])]++;
      }
    }
  }
  for(auto x : mpii){
    if(x.second == k) ans++;
  }
  cout<<ans<<"\n";
}