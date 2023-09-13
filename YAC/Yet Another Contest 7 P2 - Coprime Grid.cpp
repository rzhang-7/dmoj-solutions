#include <iostream>
using namespace std;

// https://dmoj.ca/problem/yac7p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t, n, m;
  cin>>t;
  while(t--){
    cin>>n>>m;
    if(n == 1 || m == 1) cout<<"-1\n";
    else {
      for(int i = 0; i<n; i++){
        if((i&1))
          for(int j = m; j>=1; j--)
            cout<<(j+(i*m)==n*m?1:j+(i*m)+1)<<" \n"[j==1];
        else
          for(int j = 1; j<=m; j++)
            cout<<(j==m&&i==n-1?1:j+(i*m)+1)<<" \n"[j==m];
      }
    }
  }
}