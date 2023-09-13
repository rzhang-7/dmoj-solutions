#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/usaco22decb1

const int MM = 1e5+1;

int n, arr[MM];
ll ans, cnt = 1e9;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++)
    cin>>arr[i];
  sort(arr, arr+n);
  int hi = arr[n-1], lo = arr[0];
  for(ll i = hi; i>=lo; i--){
    int num = n-(lower_bound(arr, arr+n, i)-arr);
    if(ans <= i*num){
      ans = max(ans, i*num);
      cnt = min(cnt, i);
    }
  }
  cout<<ans<<" "<<cnt<<"\n";
}