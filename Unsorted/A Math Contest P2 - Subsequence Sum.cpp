#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/mathp2

const int MOD = 1e9+7;

ll n, sum, ans;

ll quickPow(ll base, ll exp){
  if(exp == 0)
    return 1;
  ll tmp = quickPow(base, exp/2);
  if(exp%2)
    return ((tmp*tmp) % MOD * base) % MOD;
  else 
    return tmp*tmp%MOD;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0, x; i<n; i++){
    cin>>x;
    sum = (sum+x)%MOD;
  }
  cout<<sum%MOD * quickPow(2, n-1)%MOD<<"\n";
}