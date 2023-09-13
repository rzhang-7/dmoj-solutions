#include <iostream>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/ccc17j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,k, ans = 0;
  cin>>n>>k;
  for(int i = 0; i<=k; i++){
    ans += n*pow(10,i);
  }
  cout<<ans<<"\n";
}