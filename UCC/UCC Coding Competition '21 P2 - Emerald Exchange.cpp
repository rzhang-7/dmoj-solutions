#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ucc21p2

const int MM = 1e5+1;

int n, cnt, ans, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0); 
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  for(int i = 1; i<=n; i++){
    if(arr[i]%2){
      ans = max(ans, cnt);
      cnt = 0;
    } else 
      cnt += arr[i];
  }
  ans = max(ans, cnt);
  cout<<ans<<"\n";
}