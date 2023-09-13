#include <iostream>
#include <iomanip>
using namespace std;

// https://dmoj.ca/problem/ccc21s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  double ans = 0;
  cin>>n;
  int arr[n+1];
  for(int i = 0; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 0, w; i<n; i++){
    cin>>w;
    ans += w * (arr[i] + arr[i+1])/2.0;
  }
  cout<<fixed<<setprecision(1);
  cout<<ans<<"\n";
}