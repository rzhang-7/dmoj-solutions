#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/mmm14a

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  ll a, b;
  cin>>a>>b;
  for(ll i = a; i<=b; i++){  
    int ans = 0;
    ll n = i;
    if(n%2 == 0) ans++;
    while(n%2 == 0)
      n /= 2;
    for(ll j = 3; j*j <= n; j+=2){
      if(n%j==0) ans++;
      while(n%j==0){
        n /= j;
      }
    }
    if(n > 2) ans++;
    cout<<ans<<"\n";
  }
}

// can also use sieve
// loop until B, if the index is prime, increase each multiple of it by 1
// int A, B;
// cin>>A>>B;
// vector<int> f(B+1);
// for(int i = 2; i<=B; i++){
//   if(!f[i]) {   // prime
//     for(int j = i; j<=B; j+=i) f[j]++;
//   }
//   if(i >= A) cout<<f[i]<<"\n";
// }