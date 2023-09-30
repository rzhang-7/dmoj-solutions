#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/ds1

const int MM = 1e5+1;

ll n, m, arr[MM], bit[MM], freq[MM];

void update(bool ft, int idx, ll val){
  for(; idx<=MM; idx += (idx & -idx)){
    ft ? bit[idx] += val : freq[idx] += val;
  }
}

ll sum(bool ft, int idx){
  ll ans = 0;
  for(; idx > 0; idx -= (idx & -idx)){
    ans += ft ? bit[idx] : freq[idx];
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
    update(1, i, arr[i]);
    update(0, arr[i], 1);
  }
  for(int i = 1; i<=m; i++){
    char op;
    cin>>op;
    switch(op){
      case 'C':
        int x, v; cin>>x>>v;
        update(1, x, v-arr[x]);
        update(0, arr[x], -1);
        update(0, v, 1);
        arr[x] = v;
        break;
      case 'S':
        int l, r; cin>>l>>r;
        cout<<sum(1, r)-sum(1, l-1)<<"\n";
        break;
      case 'Q':
        cin>>v;
        cout<<sum(0, v)<<"\n";
        break;
    }
  }
  // for(int i = 1; i<=n; i++)cout<<bit[i]<<" \n"[i==n];
}