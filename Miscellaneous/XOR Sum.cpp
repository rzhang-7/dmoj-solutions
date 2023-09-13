#include <iostream>
using namespace std;

// https://dmoj.ca/problem/xors

int n;
long long mx, mi;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0,x; i<n; i++){
    cin>>x;
    mx += x;
    mi ^= x;
  }
  cout<<mx-mi<<"\n";
}