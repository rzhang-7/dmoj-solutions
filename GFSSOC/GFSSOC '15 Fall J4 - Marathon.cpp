#include <iostream>
using namespace std;

// https://dmoj.ca/problem/gfssoc2j4

int arr[500001];
int psa[500001];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin>>n>>q;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  psa[1] = arr[1];
  for(int i = 2; i<=n; i++){
    psa[i] = psa[i-1] + arr[i];
  }
  for(int i = 0, a, b; i<q; i++){
    cin>>a>>b;
    cout<<psa[n] - (psa[b] - psa[a-1])<<"\n";
  }
}