#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/dmopc21c4p2

const int MM = 5e6+1;

int n, ans, mx;
bool sieve[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  vector<int> v;
  for(int i = 0, x; i<n; i++){
    cin>>x;
    mx = max(mx,x);
    v.push_back(x);
  }
  sort(v.begin(),v.end());
  for(int x : v){
    if(!sieve[x]){
      ans++;
      for(int j = x; j<=mx; j+=x){
        sieve[j] = 1;
      }
    }
  }
  cout<<ans<<"\n";
}