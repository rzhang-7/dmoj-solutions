#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc16c1p5

const int MM = 5e5+1;

int n; ll bit[MM], inv;

void update(int i, int val){
  for(; i<MM; i+=i&-i) bit[i] += val;
}

ll sum(int i){
  ll ans = 0;
  for(; i>0; i-=i&-i) ans += bit[i];
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n;
  for(int i = 1, x; i<=n; i++){
    cin>>x;
    int lo = sum(x), hi = i-1 - lo;
    inv += min(lo,hi); 
    update(x, 1);
  }
  cout<<inv<<"\n";
}