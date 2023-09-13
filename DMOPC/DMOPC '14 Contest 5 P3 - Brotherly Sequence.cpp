#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc14c5p3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, ans = -1; cin>>n;
  vector<int> v(n), a(n,1);
  for(int i = 0; i<n; i++){
    cin>>v[i];
  }
  for(int i = 1; i<n; i++){
    if(abs(v[i-1] - v[i]) <= 2){
      a[i-1]++;
      a[i] = a[i-1];
    }
  }
  for(int x : a) ans = max(ans, x);
  cout<<ans<<"\n";
}