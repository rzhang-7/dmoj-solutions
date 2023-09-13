#include <iostream>
using namespace std;
const int MM = 252;

// https://dmoj.ca/problem/dmopc15c1p5

// 2d psa and query every rectangle (optimized by querying rectangles that have the maximum length for each possible width O(W*H*min(W,H)) )

int w, h, n, ans, psa[MM][MM];

int qry(int r1, int c1, int r2, int c2){
  return psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>w>>h>>n;
  for(int i = 1; i<=h; i++){
    for(int j = 1; j<=w; j++){
      cin>>psa[i][j];
    }
  }
  for(int i = 1; i<=h; i++){
    for(int j = 1; j<=w; j++){
      psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    }
  }
  int mn = min(h,n);
  for(int nh = 1; nh <= mn; nh++){
    int nw = min(w, (n/nh));
    for(int r1 = 1; r1<=h-nh+1; r1++){
      for(int c1 = 1; c1<=w-nw+1; c1++){
        int r2 = r1 + nh - 1, c2 = c1 + nw - 1;
        ans = max(ans, qry(r1, c1, r2, c2));
      }
    }
  }
  cout<<ans<<"\n";
}