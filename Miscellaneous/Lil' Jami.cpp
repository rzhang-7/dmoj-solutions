#include <iostream>
using namespace std;

// https://dmoj.ca/problem/liljami

const int MM = 1e6+1;

int n, k, q, arr[MM], psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0, x; i<k; i++){
    cin>>x;
    arr[x]++;
  }
  psa[0] = arr[0];
  for(int i = 1; i<n; i++){
    psa[i] = psa[i-1] + arr[i];
  }
  cin>>q;
  for(int i = 0, a, b; i<q; i++){
    cin>>a>>b;
    cout<<psa[b]-psa[a-1]<<"\n";
  }
}