#include <iostream>
using namespace std;

// https://dmoj.ca/problem/hkccc15j3

int n, m, ans;
bool row[100], col[100], rd[199], ld[199];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0, x, y; i<m; i++){
    cin>>x>>y;
    x--; y--;
    row[x] = true;
    col[y] = true;
    rd[x+y] = true;
    ld[x+100-1-y] = true;
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(!row[i] && !col[j] && !rd[i+j] && !ld[i+100-1-j]){
        ans++;
      }
    }
  }
  cout<<ans<<"\n";
}