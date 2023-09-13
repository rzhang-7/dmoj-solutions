#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/sac21ccp2

const int MM = 1e5;

ll n, k, ans, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr+n, greater<int>());
  for(int i = 0; i<k; i++)
    ans += arr[i];
  cout<<ans<<"\n";
}