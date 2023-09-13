#include <iostream>
using namespace std;

// https://dmoj.ca/problem/checkereasy

const int MM = 3e3+2;

int n, m, psa0[MM][MM], psa1[MM][MM];

int qry0(int r1, int c1, int r2, int c2){
  return psa0[r2][c2] - psa0[r1-1][c2] - psa0[r2][c1-1] + psa0[r1-1][c1-1];
}

int qry1(int r1, int c1, int r2, int c2){
  return psa1[r2][c2] - psa1[r1-1][c2] - psa1[r2][c1-1] + psa1[r1-1][c1-1];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  int r,c,x;
  cin>>r>>c>>x;
  while(r){
    psa0[r][c] = x;
    psa1[r][c] = x;
    cin>>r>>c>>x;
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      if(abs(j-i)%2){
        psa0[i][j] = psa0[i-1][j] + psa0[i][j-1] - psa0[i-1][j-1] - psa0[i][j];
        psa1[i][j] += psa1[i-1][j] + psa1[i][j-1] - psa1[i-1][j-1];
      }
      else {
        psa0[i][j] += psa0[i-1][j] + psa0[i][j-1] - psa0[i-1][j-1];
        psa1[i][j] = psa1[i-1][j] + psa1[i][j-1] - psa1[i-1][j-1] - psa1[i][j];
      }
    }
  }

  int r1, c1, r2, c2;
  cin>>r1>>c1>>r2>>c2;
  while(r1 && c1 && r2 && c2){
    cout<<(abs(c1-r1)%2 ? qry1(r1, c1, r2, c2) : qry0(r1, c1, r2, c2))<<"\n";
    cin>>r1>>c1>>r2>>c2;
  }
}
//   1 2 3 4 5 6
// 1 
// 2   
// 3
// 4
// 5