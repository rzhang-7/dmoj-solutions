#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/yac5p1

ll n,k,x,pw = 1;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k>>x;
  for(int i = 1; i<n; i++){
    pw = 2*pw % k;
    cout<<k-1<<" ";
  }
  pw = (pw-1+k) % k * (k-1) % k;
  cout<<(x - pw + k) % k<<"\n";
}