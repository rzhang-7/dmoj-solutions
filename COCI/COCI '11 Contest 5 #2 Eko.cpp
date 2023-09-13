#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/coci11c5p2

const int MM = 1e6+1;

ll n, m, ans = -1, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr+n);
  ll lo = 0, hi = arr[n-1];
  while(lo <= hi){
    ll mid = (lo+hi)/2, sum = 0;
    for(int i = 0; i<n; i++)
      if(arr[i] > mid)
        sum += (arr[i] - mid);
    if(sum < m)
      hi = mid-1; 
    else if(sum >= m){
      lo = mid+1;
      ans = max(ans, mid);
    }
  }
  cout<<ans<<"\n";
}