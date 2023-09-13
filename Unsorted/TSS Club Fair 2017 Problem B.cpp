#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/tss17b

const int MM = 2e5;

ll n, q, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(ll i = 0, x, y; i<n; i++){
    cin>>x>>y;
    arr[i] = ceil(sqrt(x*x + y*y));
  }
  sort(arr, arr+n);  
  for(int i = 0, r; i<q; i++){
    cin>>r;
    cout<<upper_bound(arr, arr+n, r) - arr<<"\n";
  }
}