#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc20j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int p, n, r;
  cin>>p>>n>>r;  
  int c=n,i=n,d=0;
  while(c <= p){
    c = c + i*r;
    i = i*r;
    d++;
  }
  if(c==p) cout<<d+1<<"\n";
  else cout<<d<<"\n";
}