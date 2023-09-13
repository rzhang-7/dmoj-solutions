#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/ccc14s4

const int MM = 2e3+2;

ll n, k, ans, dif[MM][MM];
map<int,int> x, y;

void printM(set<int> &s1, set<int> &s2){
  for(int i = 1; i<(int)s1.size(); i++){
    for(int j = 1; j<(int)s2.size(); j++){
      cout<<dif[i][j]<<" \n"[j==(int)s2.size()-1];
    }
  } 
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  vector<int> r(2*n+1), c(2*n+1);
  vector<vector<int>> rect(n,vector<int>(5));
  set<int> s1, s2;
  for(int i = 0; i<n; i++){
    cin>>rect[i][0]>>rect[i][1]>>rect[i][2]>>rect[i][3]>>rect[i][4];
    s1.insert(rect[i][0]); s1.insert(rect[i][2]);
    s2.insert(rect[i][1]); s2.insert(rect[i][3]);
  }
  int idx = 0;
  for(int nxt : s1){
    x[nxt] = ++idx;
    r[idx] = nxt;
  }
  idx = 0;
  for(int nxt : s2){
    y[nxt] = ++idx;
    c[idx] = nxt;
  }
  for(int i = 0; i<n; i++){
    int r1 = rect[i][0], c1 = rect[i][1], r2 = rect[i][2], c2 = rect[i][3], t = rect[i][4];
    dif[x[r1]][y[c1]] += t;
    dif[x[r2]][y[c2]] += t;
    dif[x[r2]][y[c1]] -= t;
    dif[x[r1]][y[c2]] -= t;
  }
  for(int i = 1; i<(int)s1.size(); i++){
    for(int j = 1; j<(int)s2.size(); j++){
      dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
      if(dif[i][j] >= k)
        ans += ll(r[i+1] - r[i]) * (c[j+1] - c[j]);
    }
  }
  printM(s1, s2);
  cout<<ans<<"\n";
}