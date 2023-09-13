#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// https://dmoj.ca/problem/mccc4j4

const int MM = 2003;

int n, s, k, g[MM], pt[MM];
vector<pair<int,int>> v[MM];
char c;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>s;
  int m = n/s;
  for(int i = 1; i<=m; i++){
    for(int j = 1, x; j<=s; j++){
      cin>>x;
      g[x] = i;
    }
  }
  for(int i = 1, x, y; i<=(s-1)*n/2; i++){
    cin>>x>>y>>c;  
    if(c == 'W') pt[x] += 3;
    if(c == 'L') pt[y] += 3;
    if(c == 'T') {pt[x]++; pt[y]++;}
  }
  for(int i = 1; i<=n; i++){
    v[g[i]].push_back({-pt[i], i});
  }
  cin>>k;
  for(int i = 1; i<=m; i++){
    sort(v[i].begin(), v[i].end());
    cout<<v[i][k-1].second<<" \n"[i==m];
  }
}