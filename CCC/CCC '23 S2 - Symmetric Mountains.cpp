#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc23s2

const int MM = 5001;

int n, arr[MM], mem[MM][MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 1; i<=n; i++){
    int l = 1, r = i, ans = 1e9;
    while(r <= n){
      mem[l][r] = abs(arr[l] - arr[r]) + mem[l+1][r-1];
      ans = min(ans, mem[l][r]);
      l++; 
      r++;
    }
    cout<<ans<<(i!=n?" ":"\n");
  }
}