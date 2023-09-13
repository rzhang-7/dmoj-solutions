#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc20c4p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin>>t;
  for(ll i = 0, n, s; i<t; i++){
    cin>>n>>s;
    ll tot = n*(n+1)/2, dif = tot-s;
    cout<<min(n, dif-1) - dif/2<<"\n";
  }
}