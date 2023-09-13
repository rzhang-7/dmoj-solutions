#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc18j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  int count = 0;
  string y,t;
  cin>>n>>y>>t;
  for(int i = 0; i<n; i++){
    if(y[i] == 'C' && t[i] == 'C') count++;
  }
  cout<<count<<"\n";
}