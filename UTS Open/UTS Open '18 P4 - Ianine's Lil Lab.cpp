#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/utso18p4

ll n, ans;
map<ll, vector<pair<ll,ll>>> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(ll i = 0, k, m; i<n; i++){
    cin>>k>>m;
    v[k+m].push_back({k, m});
  }
  for(auto x : v){
    sort(x.second.begin(), x.second.end(), greater<pair<ll,ll>>());
    int sz = x.second.size();
    vector<ll> psaK(sz), psaM(sz);
    psaK[0] = x.second[0].first;
    psaM[0] = x.second[0].second; 
    for(int i = 1; i<sz; i++){
      psaK[i] = psaK[i-1] + x.second[i].first;
      psaM[i] = psaM[i-1] + x.second[i].second;
    }
    for(int i = 0; i<sz; i++){
      ans = max(ans, min(psaK[i], (psaM[sz-1] - psaM[i])));
    }
  }
  cout<<ans<<"\n";
}