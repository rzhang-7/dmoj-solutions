#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc17s1

const int MM = 1e5+1;

int n, sum1, sum2, ans, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++)
    cin>>arr[i];
  for(int i = 1,x; i<=n; i++){
    cin>>x;
    sum1 += arr[i]; sum2 += x;
    if(sum1 == sum2){
      ans = max(ans, i);
    }
  }
  cout<<ans<<"\n";
}