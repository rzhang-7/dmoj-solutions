#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc19c1p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(ll i = 0, p, a, b, t; i<n; i++){
    cin>>p>>a>>b>>t;
    ll num = (t + b * p + a + b - 1) / (a + b);
    cout<<(num>p?-1:num)<<"\n";
  } 
}

//ceil(x/y) = (x+y-1)/y