#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc14j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, a, d;
  int p1 = 100, p2 = 100;
  cin>>n;
  while(n--){
    cin>>a>>d;
    if(a > d) p2 -= a;
    else if(a < d) p1 -= d;
  }
  cout<<p1<<"\n"<<p2<<"\n";
}