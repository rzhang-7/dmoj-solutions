#include <bits/stdc++.h>
using namespace std;

// https://dmoj.ca/problem/mwc15c3p3

int n, q;
string word;
char arr[25][25];
bool vis[25][25];

bool f(int r, int c, int idx){
  if(idx == (int)word.length()){
    return true;
  }
  vis[r][c] = true;
  for(int dr = -1; dr <= 1; dr++){
    for(int dc = -1; dc <= 1; dc++){
      int nr = r + dr, nc = c + dc;
      if(nc<0 || nr>=n || nc<0 || nc >=n || vis[nr][nc] || arr[nr][nc]!=word[idx]){
        continue;
      }
      if(f(nr, nc, idx+1)) return true;
    }
  }
  vis[r][c] = false;
  return false;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cin>>arr[i][j];
    }
  }
  for(int i = 0; i<q; i++){
    bool found = false;
    cin>>word;
    memset(vis, 0, sizeof(vis));
    for(int r = 0; r<n && !found; r++){
      for(int c = 0; c<n && !found; c++){
        if(arr[r][c] == word[0]) found = f(r, c, 1);
      }
    }
    cout<<(found ? "good puzzle!\n" : "bad puzzle!\n");
  }
}