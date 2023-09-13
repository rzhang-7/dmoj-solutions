#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc21j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int p = 5*n - 400;
  cout<<p<<"\n";
  if(p>100) cout<<"-1"<<"\n";
  else if(p==100) cout<<"0"<<"\n";
  else cout<<"1"<<"\n";
}