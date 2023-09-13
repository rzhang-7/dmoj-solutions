#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc18c5p3

const int MM = 2e5+2;
typedef long long ll;

int n, ans;
ll m, psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    cin>>psa[i];
    psa[i] += psa[i-1];
  }
  for(int l = 1, r = 1; r<=n; r++){
    while(l<=r && psa[r] - psa[l-1] >= m){
      l++;
    }
    ans = max(ans, r-l+1);
  }
  cout<<ans<<"\n";
}