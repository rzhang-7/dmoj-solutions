#include <iostream>
using namespace std;

// https://dmoj.ca/problem/oly20practice75

int n, m, lights[100002];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  cin>>n>>m;
  for(int i = 0, l, r; i<m; i++){
    cin>>l>>r;
    lights[l]++;
    lights[r+1]--;
  }
  for(int i = 1; i<=n; i++){
    lights[i] += lights[i-1];
    ans += lights[i] % 2;
  }

  cout<<ans<<"\n";
}