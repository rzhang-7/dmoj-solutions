#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://dmoj.ca/problem/vmss7wc16c3p2

const int MM = 2001;

int n, m, a, b; bool vis[MM]; vector<int> adj[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>a>>b;
  for(int i = 0,x,y; i<m; i++){
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  queue<int> q;
  q.push(a);
  vis[a] = true;

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    for(int nxt : adj[cur]){
      if(!vis[nxt]){
        vis[nxt] = true;
        q.push(nxt);
      }    
    }
  }
  cout<<(vis[b] ? "GO SHAHIR!" : "NO SHAHIR!")<<"\n";
}