#include <iostream>
using namespace std;

// https://dmoj.ca/problem/seed3

int s, n, w, dif[100002];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  cin>>s>>n>>w;
  
  for(int i = 1, l, r, k; i <= w; i++){
    cin>>l>>r>>k;
    dif[l] += k;
    dif[r+1] -= k;
  }

  for(int i = 1; i<=s; i++){
    dif[i] += dif[i-1];
    if(dif[i] < n) ans++;
  }

  cout<<ans<<"\n";
}