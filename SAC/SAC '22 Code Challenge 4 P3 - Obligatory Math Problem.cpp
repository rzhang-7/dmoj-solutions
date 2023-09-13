// answer is the median of the array
#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/sac22cc4p3

const int MM = 1e6;

int n, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr+n);
  cout<<(n%2 ? arr[n/2] : (arr[n/2-1] + arr[n/2])/2)<<"\n";
  // cout<<arr[n/2]<<"\n";
}