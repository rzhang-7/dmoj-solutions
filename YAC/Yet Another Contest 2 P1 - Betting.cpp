#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/yac2p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 0; i<t; i++){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<(a*d < b*d - b*c ? "YES\n" : "NO\n");
  }
}