#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/aac2p3

const int MM = 1502;

int n, m, psa[MM][MM], dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

bool qry(int r1, int c1, int sz){
  // removed checks for r1<=n, r2 > 0, c1 <=m, and c2 > 0 due to assumptions that r1 <= r2 and c1 <= c2
  int r2 = r1 + sz - 1, c2 = c1 + sz - 1;
  return (psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1]) == 0;
}

bool bfs(int i){
  // determine if a square with side length i can traverse from the upper left corner to the bottom right corner
  // use dir[4][2] for different directions
  // r2 = r1 + i, c2 = c1 + i
  // where (r1, c1) represents the upper left corner of the square
  vector<bool> vis((n+1)*(m+1), 0);
  queue<pair<int,int>> q;
  vis[m+2] = 1;
  q.push({1,1});
  while(!q.empty()){
    int r = q.front().first, c = q.front().second;
    q.pop();
    if(r == n-i+1 && c == m-i+1)
      return false;
    for(int k = 0; k<4; k++){
      int nr = r+dir[k][0], nc = c+dir[k][1];
      if(nr > 0 && nr <= n-i+1 && nc > 0 && nc <= m-i+1 && !vis[nr*(m+1)+nc] && qry(nr, nc, i)){
        vis[nr*(m+1)+nc] = 1;
        q.push({nr,nc});
      }
    }
  }
  return true;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      char c;
      cin>>c;
      psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (c=='X');
    }
  }

  int hi = 0, lo = 1;
  while(hi < min(n,m) && qry(1,1,hi+1)) hi++;
  
  while(hi >= lo){
    int mid = (hi+lo)/2;
    if(bfs(mid)){
      hi = mid-1;
    } else {
      lo = mid+1;
    }
  }
  cout<<hi<<"\n";
}