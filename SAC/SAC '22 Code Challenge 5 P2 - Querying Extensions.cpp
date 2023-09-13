#include <iostream>
using namespace std;

// https://dmoj.ca/problem/sac22cc5p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string dir;
  cin>>n>>dir;
  if(dir == "right"){
    cout<<(n%2?"right\n":"left\n");
  }
  else {
    cout<<(n%2?"left\n":"right\n");
  }
}