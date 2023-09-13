#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/mwc15c1p5

ll x, y;
string a, b; 

ll quickPow(ll base, ll exp, ll MOD){
  if(exp == 0)
    return 1;
  ll tmp = quickPow(base, exp/2, MOD);
  if(exp%2)
    return ((tmp*tmp) % MOD * base) % MOD;
  else
    return tmp*tmp%MOD;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b;
  for(int i = 0; i<(int)a.length(); i++)
    x += quickPow(tolower(a[i])-'a'+1,i+1, 10);
  x %= 10;
  
  for(int i = 0; i<(int)b.length(); i++)
    y += quickPow(tolower(b[i])-'a'+1,i+1, 10);
  y %= 10;

  if(x==0) x=10;
  if(y==0) y=10;
  
  cout<<x+y<<"\n";
}