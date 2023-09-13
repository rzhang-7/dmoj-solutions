#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/tsoc15c1p5

const int MM = 101;

int n, m, w;
queue<int> q;
vector<int> adj[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  vector<int> dist(n+1, -1), ants(n+1, -1);
  for(int i = 0, x, y; i<m; i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin>>w;
  for(int i = 0, x; i<w; i++){
    cin>>x;
    q.push(x);
    dist[x] = 0;
  }
  while(!q.empty()){
    int cur = q.front(); q.pop();
    ants[cur] = dist[cur];
    for(int nxt : adj[cur]){
      if(dist[nxt] == -1){
        dist[nxt] = dist[cur] + 4;
        q.push(nxt);
      }
    }
  }
  dist.assign(n+1, -1);
  dist[1] = 0;
  q.push(1);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]){
      if(dist[nxt] == -1 && ants[cur] >= dist[cur]){
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
    }
  }
  // for(int i = 0; i<=n; i++){
  //   cout<<ants[i]<<" \n"[i==n];
  // }
  // for(int i = 0; i<=n; i++){
  //   cout<<dist[i]<<" \n"[i==n];
  // }
  if(dist[n] == -1 || ants[n] < dist[n]) cout<<"sacrifice bobhob314\n";
  else cout<<dist[n]<<"\n";
}