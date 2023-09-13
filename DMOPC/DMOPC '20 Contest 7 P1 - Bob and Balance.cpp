#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc20c7p1

int n, ans;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n;
  vector<pair<int,int>> v(2*n+1);
  for(int i = 1, x; i<=2*n; i++){
    cin>>x;
    v[i] = {x,i};
  }
  stable_sort(v.begin(), v.end());
  for(int i = 1; i<=n; i++){
    ans += v[i].first != v[i+n].first;
  }
  cout<<ans<<"\n";
  for(int i = 1; i<=n; i++){
    cout<<v[i].second<<" "<<v[i+n].second<<"\n";
  }
}