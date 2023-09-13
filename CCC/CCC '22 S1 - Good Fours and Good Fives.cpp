#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc22s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin>>n;
  for(int i = 0; i<=n/5; i++){
    if((n-i*5)%4 == 0) ans++;
  }
  cout<<ans<<"\n";
}