#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc18c2p4

const int MM = 5e5+1;

ll n, m, psa[MM];
int ans = 1e9;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    cin>>psa[i];
    psa[i] += psa[i-1];
  }
  int l = 1, r = 1;
  while(l <= r && r<=n){    
    if(psa[r]-psa[l-1] >= m){
      ans = min(ans, r-l+1);
      l++;
    } else {
      r++;
    }
  }
  cout<<(ans == 1e9 ? -1 : ans)<<"\n";
}