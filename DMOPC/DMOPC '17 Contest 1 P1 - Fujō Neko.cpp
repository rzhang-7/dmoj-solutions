#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc17c1p1

const int MM = 1001;

int r, c, q;
bool ns[MM], ew[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>r>>c;
  for(int i = 1; i<=r; i++){
    for(int j = 1; j<=c; j++){
      char x;
      cin>>x;
      if(x == 'X'){
        ns[j] = true;
        ew[i] = true;
      }
    }
  }
  cin>>q;
  for(int i = 0, x, y; i<q; i++){
    cin>>x>>y;
    cout<<(ns[x] || ew[y] ? "Y" : "N")<<"\n";
  }
}