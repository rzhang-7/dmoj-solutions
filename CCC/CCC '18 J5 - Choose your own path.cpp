#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://dmoj.ca/problem/ccc18j5

const int MM = 1e5+1;

int n, ans = MM, dist[MM]; vector<int> adj[MM]; bool reach = true, vis[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1, m; i<=n; i++){
    cin>>m;
    for(int j = 1, x; j<=m; j++){
      cin>>x;
      adj[i].push_back(x);
    }
  }
  queue<int> q;
  q.push(1);
  vis[1] = true;
  dist[1] = 1;
  while(!q.empty()){
    int cur = q.front(); q.pop();

    if(adj[cur].empty())
      ans = min(ans, dist[cur]);

    for(int nxt : adj[cur]){
      if(!vis[nxt]){
        vis[nxt] = true;
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
    }
  }
  for(int i = 1; i<=n && reach; i++)
    if(!vis[i])
      reach = false;
  cout<<(reach ? "Y" : "N")<<"\n";
  cout<<ans<<"\n";
}