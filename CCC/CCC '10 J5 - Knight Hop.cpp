#include <iostream>
#include <queue>
using namespace std;

// https://dmoj.ca/problem/ccc10j5

int a, b, x, y;
int dist[9][9];
bool vis[9][9];
pair<int,int> moves[] = { {1,2},{2,1},{1,-2},{-2,1},{-1,2},{-1,-2},{-2,-1} };  

bool on(pair<int,int> p){
  int a = p.first;
  int b = p.second;
  return !((a<0 || a>8) || (b<0 || b>8));
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>a>>b>>x>>y;
  a--;
  b--;
  x--;
  y--;
  queue<pair<int,int>> q;
  dist[a][b] = 0;
  vis[a][b] = true;
  q.push(make_pair(a,b));
  while(!q.empty()){
    pair<int,int> cur = q.front();
    q.pop();
    for(pair<int,int> m : moves){
      pair<int,int> pos = make_pair(m.first + cur.first, m.second + cur.second);
      if(on(pos)){
        if(!vis[pos.first][pos.second]) {
          dist[pos.first][pos.second] = dist[cur.first][cur.second] + 1;
          vis[pos.first][pos.second] = true;
          q.push(pos);
        }
      }
    }
  }
  cout<<dist[x][y]<<"\n";
}