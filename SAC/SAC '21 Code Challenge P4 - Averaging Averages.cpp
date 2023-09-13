#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac21ccp4

const int MM = 1e6+1;

int n, q, psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i=1, x; i<=n; i++){
    cin>>x;
    psa[i] = psa[i-1] + x;
  }
  for(int i = 0, l, r; i<q; i++){
    cin>>l>>r;
    cout<<(psa[r] - psa[l-1])/(r-l+1)<<"\n";
  }
}