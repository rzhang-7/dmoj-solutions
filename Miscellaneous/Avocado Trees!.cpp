#include <iostream>
using namespace std;

// https://dmoj.ca/problem/avocadotrees

const int MM = 1e6+1;

int n, q, h, ans = -1, tree[MM][2], psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q>>h;
  for(int i = 1; i<=n; i++){
    cin>>tree[i][0]>>tree[i][1];
    if(tree[i][0] > h) tree[i][1] = 0;
  }
  psa[1] = tree[1][1];
  for(int i = 2; i<=n; i++){
    psa[i] = psa[i-1] + tree[i][1];
  }
  for(int i = 1, l, r; i<=q; i++){
    cin>>l>>r;
    ans = max(ans, psa[r]-psa[l-1]);
  }
  cout<<ans<<"\n";
}