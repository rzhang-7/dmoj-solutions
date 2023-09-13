#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/usaco20janb2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  int b[n-1], a[n];
  for(int i = 0; i<n-1; i++){
    cin>>b[i];
  }
  for(int k = 1; k<=n; k++){
    a[0] = k;
    for(int i = 1; i<n; i++){
      a[i] = b[i-1] - a[i-1];
    }
    int ans[n];
    copy(a, a+n, ans);
    sort(a, a+n);
    bool good = true;
    for(int i= 0; i<n;i++){
      if(a[i] != i+1) good = false;
    }
    if(good){
      for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
      }
      cout<<"\n";
    }
  }
}