#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://dmoj.ca/problem/ccc09s3

// adjacency matrix
vector<vector<int>> adj(51, vector<int>(51,0));

// count the number of nodes that are exactly 2 edges away from the node x
int f(int x){
  int cnt = 0;
  vector<vector<int>> temp = adj;

  // find a node that is directly connected to x
  for(int i = 1; i<=50; i++)
    if(temp[x][i] == 1)
      // check for the node's neighbours and check that they aren't connected to x
      for(int j = 1; j<=50; j++)
        if(temp[i][j] == 1 && j != x && temp[x][j] == 0)
          temp[x][j] = 2;

  for(int i = 1; i<=50; i++)
    if(temp[x][i] == 2)
      cnt++;

  return cnt;
}

// modified bfs to find the shortest path
int bfs(int x, int y){
  queue<int> q;
  vector<bool> vis(51, false);
  vector<int> dist(51, -1);

  // mark the starting point
  vis[x] = true;
  dist[x] = 0;
  q.push(x);

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    // shortest path has been found
    if(cur == y)
      return dist[cur];

    for(int nbr = 1; nbr<=50; nbr++){
      // check if node is connected and if it hasn't been visited before
      if(adj[cur][nbr] && !vis[nbr]){
        
        vis[nbr] = true;
        // increase distance by 1
        dist[nbr] = dist[cur] + 1;
        
        q.push(nbr);
      }
    }
  }
  return -1;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  adj[1][6] = 1; adj[6][1] = 1;
  adj[2][6] = 1; adj[6][2] = 1;
  adj[3][4] = 1; adj[4][3] = 1;
  adj[3][5] = 1; adj[5][3] = 1;
  adj[3][6] = 1; adj[6][3] = 1;
  adj[3][15] = 1; adj[15][3] = 1;
  adj[4][5] = 1; adj[5][4] = 1;
  adj[4][6] = 1; adj[6][4] = 1;
  adj[5][6] = 1; adj[6][5] = 1;
  adj[6][7] = 1; adj[7][6] = 1;
  adj[7][8] = 1; adj[8][7] = 1;
  adj[8][9] = 1; adj[9][8] = 1;
  adj[9][10] = 1; adj[10][9] = 1;
  adj[9][12] = 1; adj[12][9] = 1;
  adj[10][11] = 1; adj[11][10] = 1;
  adj[11][12] = 1; adj[12][11] = 1;
  adj[12][13] = 1; adj[13][12] = 1;
  adj[13][14] = 1; adj[14][13] = 1;
  adj[13][15] = 1; adj[15][13] = 1;
  adj[16][17] = 1; adj[17][16] = 1;
  adj[16][18] = 1; adj[18][16] = 1;
  adj[17][18] = 1; adj[18][17] = 1;
  
  char qry;
  for(cin>>qry; qry != 'q'; cin>>qry){
    int x, y;
    if(qry == 'i'){
      cin>>x>>y;
      adj[x][y] = 1;
      adj[y][x] = 1;
    }
    if(qry == 'd'){
      cin>>x>>y;
      adj[x][y] = 0;
      adj[y][x] = 0;
    }
    if(qry == 'n'){
      cin>>x;
      int cnt = 0;
      for(int i = 1; i<=50; i++){
        if(adj[x][i])
          cnt++;
      }
      cout<<cnt<<"\n";
    }
    if(qry == 'f'){
      cin>>x;
      cout<<f(x)<<"\n";
    }
    if(qry == 's'){
      cin>>x>>y;
      int ans = bfs(x, y);
      cout<<(ans == -1 ? "Not connected" : to_string(ans))<<"\n";
    }
  }
}