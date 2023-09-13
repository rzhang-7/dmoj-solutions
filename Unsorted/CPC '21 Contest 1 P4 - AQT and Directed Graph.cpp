#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/cpc21c1p4

const int MM = 3e5+1;

int n, m, vis[MM];
vector<int> adj[MM];

void dfs(int u, int l){
  vis[u] = l;
  for(int v : adj[u]){
    if(!vis[v]) dfs(v, l);
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0, a, b; i<m; i++){
    cin>>a>>b;
    adj[b].push_back(a);
  }
  for(int i = n; i >= 1; i--){
    if(!vis[i]) dfs(i, i);
  }
  for(int i = n; i >= 1; i--){
    if(vis[i] > i) {
      cout<<i<<" "<<vis[i]<<"\n";
      return 0;
    }
  }
  cout<<"-1\n";
}