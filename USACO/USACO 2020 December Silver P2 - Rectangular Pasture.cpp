#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/usaco20decs2

const int MM = 2503;

int n, x[MM], y[MM], psa[MM][MM];
map<int, int> cx, cy;
ll ans;

int qry(int r1, int c1, int r2, int c2){
  return psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>x[i]>>y[i];
    cx[x[i]] = cy[y[i]] = 0;
  }
  int rank = 0;
  for(auto &i : cx) i.second = ++rank;
  rank = 0; for(auto &i : cy) i.second = ++rank;
  for(int i = 1; i<=n; i++){
    x[i] = cx[x[i]]; y[i] = cy[y[i]]; psa[x[i]][y[i]] = 1;
  }
  for(int i = 1; i<=n; i++){
    for(int j = 1 ; j<=n; j++){
      psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    }
  }
  for(int i = 1; i<=n; i++){
    for(int j = i; j<=n; j++){
      int r1 = min(x[i], x[j]), r2 = max(x[i], x[j]), c1 = min(y[i], y[j]), c2 = max(y[i], y[j]);
      int left = qry(r1, 1, r2, c1), right = qry(r1, c2, r2, n);
      ans += (ll)left * right;
    }
  }
  cout<<ans+1<<"\n";
}