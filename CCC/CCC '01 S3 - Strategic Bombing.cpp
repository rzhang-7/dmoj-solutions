#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc01s3

int ans;
vector<pair<int,int>> e;
vector<vector<int>> adj(26);

void removeEdge(int a, int b){
  adj[a].erase(remove(adj[a].begin(), adj[a].end(), b), adj[a].end());
  adj[b].erase(remove(adj[b].begin(), adj[b].end(), a), adj[b].end());
}

bool bfs(int a, int b){
  queue<int> q;
  vector<bool> vis(26, 0);
  vis[a] = true;
  q.push(a);
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]){
      if(!vis[nxt]){
        vis[nxt] = true;
        q.push(nxt);
      }
    }
  }
  return !vis[b];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  char a, b;
  for(cin>>a>>b; a != '*'; cin>>a>>b){
    if(a != '*'){
      adj[a-'A'].push_back(b-'A');
      adj[b-'A'].push_back(a-'A');
      e.push_back({a-'A', b-'A'});
    }
  }
  for(auto i : e){
    int x = i.first, y = i.second;
    removeEdge(x, y);
    if(bfs(x, y)){
      cout<<(char)(x+'A')<<(char)(y+'A')<<"\n";
      ans++;
    }
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cout<<"There are "<<ans<<" disconnecting roads.\n";
}