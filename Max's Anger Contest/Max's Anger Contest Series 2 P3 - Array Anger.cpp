#include <iostream>
using namespace std;

// https://dmoj.ca/problem/macs2p3

const int MM = 2e5+1;

int n, q, psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>q;
  for(int i = 1,x; i<=n; i++){
    cin>>x;
    psa[i] = psa[i-1] + x;
  }
  for(int i = 1, l, s; i<=q; i++){
    string temp;
    cin>>temp>>l>>s;
    // can also use distance(psa,lower_bound(psa,psa+n,s+psa[l-1]))
    int lo = l, hi = n;
    while(lo < hi){
      int mid = (lo+hi)/2;
      if(psa[mid] - psa[l-1] < s){
        lo = mid + 1;  
      }
      else hi = mid;
    }
    cout<<lo<<"\n";
  }
}