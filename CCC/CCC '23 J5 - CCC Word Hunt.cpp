#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc23j5

const int MM = 100;

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1} , {-1, -1}};
char arr[MM][MM];
string str;
int R, C, ans = 0;

void fun(int r, int c, int k, int idx, bool turn){
  if(idx == (int)str.length()){
    ans++;
    return;
  }
  for(int i = k-2; i<=k+2; i+=2){ 
    int nk = (i+8)%8, nr = r + dir[nk][0], nc = c + dir[nk][1];
    if(0<=nr && nr<R && 0<=nc && nc<C && arr[nr][nc] == str[idx] && (nk == k || !turn)){
      fun(nr, nc, nk, idx+1, turn || nk != k);
    }
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>str>>R>>C;
  for(int i = 0; i<R; i++){
    for(int j = 0; j<C; j++){
      cin>>arr[i][j];
    }
  }
  for(int i = 0; i<R; i++){
    for(int j = 0; j<C; j++){
      if(arr[i][j] == str[0]){
        for(int k = 0; k<8; k++){
          int nr = i + dir[k][0], nc = j + dir[k][1];
          if(0<=nr && nr<R && 0<=nc && nc<C && arr[nr][nc] == str[1]){
            fun(nr, nc, k, 2, false);
          }
        }
      }
    }
  }
  cout<<ans<<"\n";
}