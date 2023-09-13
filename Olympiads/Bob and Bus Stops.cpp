#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/oly20practice82

const int MM = 1e5;

int n, q, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr + n);
  for(int i = 0, l, r; i<q; i++){
    cin>>l>>r;
    cout<<upper_bound(arr, arr+n, r) - lower_bound(arr, arr+n, l)<<"\n"; 
  }
}