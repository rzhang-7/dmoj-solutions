#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmpg15s5

const int MM = 1e4+2;

int n, m, ans;
bool dif[MM][MM];

// void printM(){
//   for(int i = 0; i<=n+2; i++){
//     for(int j = 0; j<=n+2; j++){
//       cout<<dif[i][j]<<" \n"[j==n+2];
//     }
//   }
//   cout<<"\n--------------------\n";  
// }

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0, x, y, w, h; i<m; i++){
    cin>>x>>y>>w>>h; x++; y++;
    dif[x][y] = !dif[x][y]; 
    dif[x+w][y] = !dif[x+w][y];
    dif[x][y+h] = !dif[x][y+h];
    dif[x+w][y+h] = !dif[x+w][y+h];
  }
  for(int i = 1; i<=n+1; i++){
    for(int j = 1; j<=n+1; j++){
      dif[i][j] = int(dif[i-1][j] + dif[i][j-1] + dif[i][j] - dif[i-1][j-1])%2;
      if(dif[i][j]) ans++;
    }
  }
  cout<<ans<<"\n";
}