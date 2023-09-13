#include <iostream>
using namespace std;

// https://dmoj.ca/problem/usaco21decb2

const int MM = 1e5+2;

int n, ans = 0, desire[MM], delta[MM], dif[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>desire[i];
  }
  for(int i = 1, x; i<=n; i++){
    cin>>x;
    delta[i] = desire[i] - x;
  }

  for(int i = 1; i<=n+1; i++){
    dif[i] = delta[i] - delta[i-1];
    if(dif[i] > 0) ans += dif[i];
  }
  cout<<ans<<"\n";
}