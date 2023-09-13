#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc17j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a,b,c,d,s;
  cin>>a>>b>>c>>d>>s;
  int dist = abs(a-c) + abs(b-d);
  if(s < dist) cout<<"N\n";
  else{
    (s-dist)%2 == 0 ? cout<<"Y\n" : cout<<"N\n";
  }
}