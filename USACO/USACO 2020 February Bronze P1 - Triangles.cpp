#include <iostream>
using namespace std;

// https://dmoj.ca/problem/usaco20febb1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int x[n], y[n];
  for(int i = 0; i<n; i++){
    cin>>x[i];
    cin>>y[i];
  }
  int ans = 0;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){ // i-j parallel with x
      for(int k = 0; k<n; k++){ // i--k parallel with y
        if(y[i] == y[j] && x[i] == x[k]){
          int area = abs(x[i]-x[j]) * abs(y[i] - y[k]);
          ans = max(ans, area);
        }
      }
    }
  }
  cout<<ans<<"\n";
}