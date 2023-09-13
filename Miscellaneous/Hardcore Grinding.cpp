#include <iostream>
using namespace std;

// https://dmoj.ca/problem/grind

const int MM = 1e7+3;

int n, dif[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  cin>>n;
  for(int i = 1, l, r; i <= n; i++){
    cin>>l>>r;
    dif[l]++;
    dif[r]--;
  }
  for(int i = 1; i<MM; i++){
    dif[i] += dif[i-1];
    ans = max(ans, dif[i]);
  }
  cout<<ans<<"\n";
}