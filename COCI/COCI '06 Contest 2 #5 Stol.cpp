#include <iostream>
using namespace std;

// https://dmoj.ca/problem/coci06c2p5

const int MM = 402;

int r, c, ans, psa[MM][MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>r>>c;
  for(int i = 1; i<=r; i++){
    for(int j = 1; j<=c; j++){
      char x;
      cin>>x;
      psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + (x=='X');
    }
  }
  for(int r1 = 1; r1 <= r; r1++){
    for(int r2 = r1; r2 <= r; r2++){
      for(int c1 = 1, c2 = 1; c2<=c; c2++){
        int n = psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1];
        if(n) c1 = c2+1;
        else ans = max(ans, 2*(r2-r1+1) + 2*(c2-c1+1));
      }
    }
  }
  cout<<ans-1<<"\n";
}