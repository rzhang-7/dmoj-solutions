#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 1001;
const int MM = 1e6+1;

// https://dmoj.ca/problem/ccc20s2

int n, m; bool vis[MAX_N][MAX_N];
vector<vector<pair<int,int>>> adj(MM);

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);  
  cin>>m>>n;
  for(int i = 1; i<=m; i++){
    for(int j = 1, x; j<=n; j++){
      cin>>x;
      adj[x].push_back({i,j});
    }
  }

  queue<pair<int,int>> q;
  vis[m][n] = true;
  q.push({m,n});

  while(!q.empty()){
    int r = q.front().first, c = q.front().second;
    q.pop();
    
    for(auto nxt : adj[r*c]){
      if(nxt.first == 1 && nxt.second == 1){
        cout<<"yes\n";
        return 0;
      }
      if(!vis[nxt.first][nxt.second]){
        vis[nxt.first][nxt.second] = true;
        q.push(nxt);
      }
    }
  }
  cout<<"no\n";
}