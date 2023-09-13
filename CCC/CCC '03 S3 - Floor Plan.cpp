#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// https://dmoj.ca/problem/ccc03s3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, r, c, ans = 0;
  cin>>n>>r>>c;
  vector<int> sizes;
  vector<vector<bool>> adj(r, vector<bool>(c,0)), vis = adj;
  int dir[4][2] = {{1,0}, {0,-1}, {-1,0}, {0,1}};
  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
      char x;
      cin>>x;
      if(x == '.') adj[i][j] = 1;
    }
  }
  for(int i = 0; i<r; i++){
    for(int j = 0; j<c; j++){
      if(adj[i][j] && !vis[i][j]){
        int cnt = 1;
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
          int x = q.front().first, y = q.front().second;
          q.pop();
          for(int k = 0; k<4; k++){
            int nx = x + dir[k][0], ny = y + dir[k][1];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && adj[nx][ny] && !vis[nx][ny]){
              vis[nx][ny] = 1;
              cnt++;
              q.push({nx, ny});
            }
          }
        }
        sizes.push_back(cnt);
      }
    }
  }
  sort(sizes.begin(), sizes.end(), greater<int>());
  for(int x : sizes){ 
    if(n-x >= 0){ 
      n-=x;
      ans++;
    }
    else break;
  }
  cout<<ans<<" room";
  if(ans != 1) cout<<"s";
  cout<<", "<<(n > 0 ? n : 0)<<" square metre(s) left over\n";
}