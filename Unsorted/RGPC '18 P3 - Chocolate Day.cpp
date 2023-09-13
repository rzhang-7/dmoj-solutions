#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/rgpc18p3

const int MM = 1e6+2;

ll n, t, k, ans, dif[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  for(int i = 0, a, b, c; i<t; i++){
    cin>>a>>b>>c;
    dif[b+1]-=c;
    dif[a]+=c;
  }
  cin>>k;
  for(int i = 1; i<=n; i++){
    dif[i] += dif[i-1];
  }
  for(ll l = 0, r = 1; r<=n; r++){
    dif[r] += dif[r-1];
    if(dif[r] - dif[l] <= k) ans = max(ans, r-l);
    else l++;
  }
  cout<<ans<<"\n";
}