#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/oly20practice119

const int MOD = 1e9+7;

ll quickPow(ll base, ll exp){
  if(exp == 0)
    return 1;
  ll tmp = quickPow(base, exp/2);
  if(exp % 2 == 1)
    return ((tmp*tmp) % MOD * base) % MOD;
  else
    return tmp*tmp%MOD;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    ll a, b, c, k;
    cin>>a>>b>>c>>k;
    if(c-b == b-a){
      cout<<(a+(b-a)*(k-1)%MOD)%MOD<<"\n";
    } else {
      cout<<(a * quickPow((c/b), k-1))%MOD<<"\n";
    }
  }
}