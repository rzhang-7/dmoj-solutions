#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/tle17c2p2

const int MM = 5e5;

int n, k, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>k;
  for(int i = 0; i<k; i++)
    cin>>arr[i];
  sort(arr,arr+k);
  cin>>n;
  for(int i = 0, f; i<n; i++){
    cin>>f;
    cout<<f - (lower_bound(arr, arr+k, f) - arr)<<"\n";
  }
}