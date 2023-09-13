#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/usaco22jans2

const int MM = 3e5+2;

int n, arr[MM];
ll ans;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++) cin>>arr[i];
  stack<ll> stk;
  for(ll i = 1; i<=n; i++){
    while(!stk.empty() && arr[stk.top()] < arr[i]){
      ans += (i-stk.top()+1);
      stk.pop();
    }
    if(!stk.empty()) ans+=i-stk.top()+1;
    stk.push(i);
  }
  cout<<ans<<"\n";
}