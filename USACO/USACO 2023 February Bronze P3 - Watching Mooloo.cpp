#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/usaco23febb3

const int MM = 1e5+1;

ll n, k, ans, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  arr[0] = -1 * INT32_MAX;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 1; i<=n; i++){
    ans += min(k+1, arr[i] - arr[i-1]);
  }
  cout<<ans<<"\n";
}