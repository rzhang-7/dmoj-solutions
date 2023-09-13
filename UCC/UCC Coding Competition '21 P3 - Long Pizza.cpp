#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/ucc21p3

const int MM = 1e7+2;

ll n, x, y, t, ans, dif[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>x>>y>>t;
  for(int i = 0, l, r; i<t; i++){
    cin>>l>>r;
    dif[l]++;
    dif[r+1]--;
  }
  for(int i = 1; i<=y; i++){
    dif[i] += dif[i-1];
    if(i>=n) ans += dif[i];
  }
  cout<<ans<<"\n";
}