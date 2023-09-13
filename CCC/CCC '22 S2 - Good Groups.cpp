#include <iostream>
#include <map>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc22s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int x, y, g, ans = 0;
  map<string,int> map;
  cin>>x;
  string x1[x], x2[x];
  for(int i = 0; i<x; i++){
    cin>>x1[i]>>x2[i];
  }
  cin>>y;
  string y1[y], y2[y];
  for(int i = 0; i<y; i++){
    cin>>y1[i]>>y2[i];
  }
  cin>>g;
  for(int i = 0; i<g; i++){
    string a, b, c;
    cin>>a>>b>>c;
    map[a] = i; 
    map[b] = i; 
    map[c] = i;
  }
  for(int i = 0; i<x; i++){
    int a = map[x1[i]], b = map[x2[i]];
    if(a != b) ans++;
  }
  for(int i = 0; i<y; i++){
    int a = map[y1[i]], b = map[y2[i]];
    if(a == b) ans++;
  }
  cout<<ans<<"\n"; 
}