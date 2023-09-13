#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/usaco23febb1

ll n, t, ans, last, d, b, rem;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  for(ll i = 1; i<=n; i++){
    cin>>d>>b;
    ans += b;
    rem -= d - last;
    last = d;
    rem = max(rem, 0LL) + b;
  }
  rem -= t - last + 1;
  rem = max(rem, 0LL);
  cout<<ans - rem<<"\n";
}