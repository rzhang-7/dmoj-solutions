#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc22c4p1

const int MM = 1e6+2;

int n, m, k, ans, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  arr[n+1] = m+1;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 1; i<=n+1; i++){
    if(i > 1) ans = max(ans, arr[i] - max(arr[i-1]-k, arr[i-2])-1);
    if(i <= n) ans = max(ans, min(arr[i]+k, arr[i+1]) - arr[i-1]-1);
  }
  cout<<ans<<"\n";
}