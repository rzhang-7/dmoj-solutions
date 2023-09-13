#include <iostream>
using namespace std;

// https://dmoj.ca/problem/aac5p1

int n, odd, even, ans;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0, x; i<n; i++){
    cin>>x;
    x % 2 ? odd++ : even++;
  }
  ans += odd/2;
  ans += even/2;
  cout<<ans<<"\n";
}