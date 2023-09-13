#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc22j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,p,f;
  int star = 0;
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>p>>f;
    if(p*5 - f*3 > 40) star++;
  }
  star == n ? cout<<star<<"+\n" : cout<<star<<"\n";
}