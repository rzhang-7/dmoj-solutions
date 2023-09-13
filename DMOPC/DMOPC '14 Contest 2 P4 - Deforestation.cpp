#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc14c2p4

int arr[1000001], psa[1000001];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>arr[i];    
  }
  psa[0] = arr[0];
  for(int i = 1; i<n; i++){
    psa[i] = psa[i-1] + arr[i];
  }
  cin>>q;
  for(int i = 0, a, b; i<q; i++){
    cin>>a>>b;
    cout<<psa[b] - psa[a-1]<<"\n";
  }
}