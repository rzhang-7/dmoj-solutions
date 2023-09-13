#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc17j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int x,y;
  cin>>x>>y;
  if(x > 0 && y > 0) cout<<1<<"\n";
  else if(x < 0 && y > 0) cout<<2<<"\n";
  else if(x < 0 && y < 0) cout<<3<<"\n";
  else if(x > 0 && y < 0) cout<<4<<"\n";
}