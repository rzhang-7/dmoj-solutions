#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

// https://dmoj.ca/problem/dmopc16c4p2

int B, F; ll ans;
vector<int> pts, fail;
vector<pi> bat;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>B;
  for(ll i = 1, f, e, p; i<=B; i++){
    cin>>f>>e>>p;
    bat.push_back({f,e});
    pts.push_back(p);
  }
  cin>>F;
  for(int i = 1, t; i<=F; i++){
    cin>>t;
    fail.push_back(t);
  }
  sort(fail.begin(), fail.end());
  for(int i = 0; i<B; i++){
    // if the indexes of batched causes are not found in fail, then they match (either too high or too low)
    if(lower_bound(fail.begin(), fail.end(), bat[i].first) == lower_bound(fail.begin(), fail.end(), bat[i].second+1)){
      ans += pts[i];
    }
  }
  cout<<ans<<"\n";
}