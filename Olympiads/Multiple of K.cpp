#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/oly19practice19

const int MM = 1e6+2;

int n, k, ans, psa[MM];
map<int,int> m;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 1, x; i<=n; i++){
    cin>>x;
    psa[i] = (psa[i-1]+x)%k;
  }
  for(int i = 1; i<=n; i++){
    if(psa[i] == 0)
      ans = i;
    else if(m[psa[i]])
      ans = max(ans, i - m[psa[i]]);
    else
      m[psa[i]] = i;
  }
  cout<<(ans ? ans : -1)<<"\n";
}