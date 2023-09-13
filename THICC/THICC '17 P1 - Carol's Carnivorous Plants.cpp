#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/thicc17p1

const int MOD = 1e9+7;

int n, m; ll ans;

ll qpow(ll x, ll exp){
  if(exp == 0) return 1;
  ll t = qpow(x, exp/2);
  t = t*t % MOD;
  return exp % 2 == 0 ? t : t*x % MOD;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  vector<int> a(n);
  for(int i = 0; i<n; i++){
    cin>>a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  for(int i = 0; i<n; i++){
    ans = (ans + qpow(a[i], i/m))%MOD;
  }
  cout<<ans<<"\n";
}