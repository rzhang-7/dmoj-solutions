#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc20j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int s,m,l;
  cin>>s>>m>>l;
  if(s + 2*m + 3*l >= 10) cout<<"happy"<<"\n";
  else cout<<"sad"<<"\n";
}