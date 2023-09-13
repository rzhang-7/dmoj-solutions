#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc21j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string dir, pre;
  for(cin>>n; n!=99999; cin>>n){
    int a = n/10000, b = n/1000, val = n%1000;
    if((a+b) % 2 != 0) dir = "left";
    else if(a + b == 0) dir = pre;
    else dir = "right";
    pre = dir;
    cout<<dir<<" "<<val<<"\n";
  }
}