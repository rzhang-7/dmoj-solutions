#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/mnyc17p3

const int MM = 1e6+2, base = 137, MOD = 1e9+7;

int len;
ll ha[MM], hb[MM], pw[MM];

ll qry(ll hsh[], int l, int r){
  return (hsh[r] - hsh[l-1] * pw[r-l+1] % MOD + MOD) % MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string a, b;
  cin>>a>>b;
  int A = a.length(), B = b.length();
  pw[0] = 1;
  for(int i = 1; i<= max(A, B); i++){
    pw[i] = pw[i-1] * base % MOD;
  }
  for(int i = 1; i<=A; i++){
    ha[i] = (ha[i-1] * base + a[i-1]) % MOD;
  }
  for(int i = 1; i<=B; i++){
    hb[i] = (hb[i-1] * base + b[i-1]) % MOD;
  }
  for(int i = 1; i<=min(A, B); i++){
    ll subA = qry(ha, A-i+1, A), subB = qry(hb, 1, i);
    if(subA==subB)
      len = i;
  }
  cout<<a<<b.substr(len)<<"\n";
}