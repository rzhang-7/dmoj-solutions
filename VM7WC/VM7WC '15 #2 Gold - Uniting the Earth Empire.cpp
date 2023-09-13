#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/vmss7wc15c2p3

ll n, ans;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  stack<pair<ll,ll>> stk;
  for(ll i = 1, x; i<=n; i++){
    cin>>x;
    pair<ll,ll> p = {x, 1};
    while(!stk.empty() && stk.top().first <= p.first){
      ans += stk.top().second;
      if(stk.top().first == p.first) p.second += stk.top().second;
      stk.pop();
    }
    if(!stk.empty()){
      ans++;
    }
    stk.push(p);
  }
  cout<<ans<<"\n";
}