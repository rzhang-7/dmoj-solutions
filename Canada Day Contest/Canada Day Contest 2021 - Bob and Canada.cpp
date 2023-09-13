#include <iostream>
using namespace std;

// https://dmoj.ca/problem/canada21p1

const int MM = 1e6+2;

int t, n, r[MM], w[MM]; string s;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--){
    cin>>n>>s;
    for(int i = 1; i<=n; i++){
      r[i] = r[i-1] + (s[i-1] == 'R');
      w[i] = w[i-1] + (s[i-1] == 'W');
    }
    int ans = n, best = w[1] - r[1];
    for(int j = 2; j<n; j++){
      ans = min(ans, best+r[j]-w[j]+w[n]);
      best = min(best, w[j]-r[j]);
    }
    cout<<ans<<"\n";
  }
}