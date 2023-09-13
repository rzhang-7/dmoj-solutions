#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc21c3p2

const int MM = 1e6;

ll k;
unordered_map<ll, int> mp;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>k;
  if(k == 0) {cout<<"1\n1\n"; return 0;}
  for(ll i = 0; i<=MM; i++){
    mp[(i+1)*i/2] = i;
  }
  for(ll i = 1; i <= MM; i++){
    ll cur = (i+1)*i/2, res = k - cur;
    if(!mp.count(res)) continue;
    int n = i, m = mp[res];
    
    if(m) {
      if(n+m+1 > MM) continue;
      cout<<n+1+m<<"\n";
      for(int j = 0; j<n; j++){
        cout<<"0 ";
      }
      cout<<"1";
      for(int j = 0; j<m; j++){
        cout<<" 0";
      }
      cout<<"\n"; return 0;
    } else {
      cout<<n<<"\n";
      for(int j = 0; j<n; j++) cout<<0<<" \n"[j==n-1];
      return 0;
    }
  }
  cout<<"-1\n";
}