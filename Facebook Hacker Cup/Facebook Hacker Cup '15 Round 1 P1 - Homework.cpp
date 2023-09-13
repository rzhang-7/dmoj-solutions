#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/fhc15c1p1

const int MM = 1e7+2;

int t, arr[MM]; // cnt[MM]
bool prime[MM];
vector<int> v[150];
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  fill(prime, prime+MM, 1);
  for(int i = 2; i<=MM; i++){
    if(!prime[i]) continue;
    arr[i]++;
    for(int j = 2*i; j<=MM; j+=i){
      arr[j]++; prime[j] = 0;
    }
  }
  for(int i = 2; i<=MM; i++){
    v[arr[i]].push_back(i);
  }
  cin>>t;
  for(int x = 1; x<=t; x++){
    int a, b, k;
    cin>>a>>b>>k;
    cout<<"Case #"<<x<<": ";
    if(k>=150) cout<<0<<"\n";
    else {
      cout<<lower_bound(v[k].begin(), v[k].end(), b+1)-upper_bound(v[k].begin(), v[k].end(), a-1)<<"\n";
    }
  }
}