#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc22c2p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  string a, b;
  cin>>n>>a>>b;
  for(int i = 0; i<n; i++){
    int j = i, len = 0;
    while(a[j] != b[j]){
      len++;
      j++;
    }
    i += len;
    if(len) ans++;
  }
  cout<<ans<<"\n";
}