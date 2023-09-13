#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/oly19practice25

const int MM = 5e3+2;

ll n, m, k, q, cake[MM][MM];
ll ans;

// void printM(){
//   for(int i = 1; i<=m; i++){
//     for(int j = 1; j<=n; j++){
//       cout<<cake[i][j]<<" \n"[j==n];
//     }
//   } cout<<"\n----------\n";  
// }

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i = 1, x, y, a, b; i<=k; i++){
    cin>>x>>y>>a>>b;
    // y axis is flipped, [i][j] are swapped
    y = m-y+1; b = m-b+1;
    cake[b][x]++;
    cake[y+1][a+1]++;    
    cake[y+1][x]--;
    cake[b][a+1]--;
  }
  for(int i = 1; i<=m; i++){
    for(int j = 1; j<=n; j++){
      cake[i][j] = cake[i][j] + cake[i][j-1] + cake[i-1][j] - cake[i-1][j-1];
    }
  }
  // printM();
  for(int i = 1; i<=m; i++){
    for(int j = 1; j<=n; j++){
      cake[i][j] = cake[i][j] + cake[i][j-1] + cake[i-1][j] - cake[i-1][j-1];
    }
  }
  cin>>q;
  for(int i = 1, a, b, c, d; i<=q; i++){
    cin>>a>>b>>c>>d;
    b = m-b+1; d = m-d+1;
    // cout<<cake[d][c]<<" - "<<cake[b-1][c]<<" - "<<cake[d][a-1]<<" + "<<cake[b-1][a-1]<<" = ";
    cout<<cake[b][c] - cake[b][a-1] - cake[d-1][c] + cake[d-1][a-1]<<"\n";
  }
  // printM();
}