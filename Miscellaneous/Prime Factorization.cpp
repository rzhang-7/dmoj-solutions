#include <iostream>
using namespace std;

// https://dmoj.ca/problem/primefactor

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  while(n--){
    int m; cin>>m;
    while(m%2==0){
      cout<<2<<" ";
      m /= 2;
    }
    for(int i=3; i*i<=m; i+=2){
      while(m%i==0){
        cout<<i<<" ";
        m /= i;
      }
    }
    if(m>2) cout<<m;
    cout<<"\n";
  }
}