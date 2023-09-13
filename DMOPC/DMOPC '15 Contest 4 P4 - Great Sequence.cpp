#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc15c4p4

const int MM = 1e5+1;

int n, k, q, psa[MM];
map<int,vector<int>> m;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k>>q;
  for(int i = 1, x; i<=n; i++){
    cin>>x;
    psa[i] = psa[i-1] + x;
    m[x].push_back(i);
  }
  for(int i = 1,a,b,x,y; i<=q; i++){
    cin>>a>>b>>x>>y;
    if(psa[y] - psa[x-1] > k && !m[a].empty() && !m[b].empty()){
      int pa = lower_bound(m[a].begin(), m[a].end(), x) - m[a].begin(),
      pb = lower_bound(m[b].begin(), m[b].end(), x) - m[b].begin();
      if(pa != m[a].size() && m[a][pa] <= y && pb != m[b].size() && m[b][pb] <= y){
        cout<<"Yes\n";
      } else cout<<"No\n";
    }
    else 
      cout<<"No\n";
  }
}