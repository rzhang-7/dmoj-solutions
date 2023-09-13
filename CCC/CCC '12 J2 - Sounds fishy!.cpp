#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc12j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a == b && b == c && c == d) cout<<"Fish At Constant Depth\n";
  else if(a > b && b > c && c > d) cout<<"Fish Diving\n";
  else if(a < b && b < c && c < d) cout<<"Fish Rising\n";
  else cout<<"No Fish\n";
}