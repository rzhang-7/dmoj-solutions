#include <iostream>
using namespace std;

// https://dmoj.ca/problem/coci16c1p1

int x, n, cnt;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>x>>n;
  for(int i = 0, p; i<n; i++){
    cin>>p;
    cnt += x;
    cnt -= p;
  }
  cout<<cnt + x<<"\n";
}