#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/coci10c3p5

const int MM = 3e5+2;
const int INF = 1e9;

int n, arr[MM];
ll ans;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  arr[n+1] = INF;
  stack<int> stk;
  for(int i = 1; i<=n+1; i++){
    while(!stk.empty() && arr[stk.top()] < arr[i]){
      int idx = stk.top(); stk.pop();
      int r = i, l = stk.empty() ? 0 : stk.top();
      ans += (ll)(r-idx) * (idx-l) * arr[idx];
    }
    stk.push(i);
  }
  while(!stk.empty()) stk.pop();
  arr[n+1] = -INF;
  for(int i = 1; i<=n+1; i++){
    while(!stk.empty() && arr[stk.top()] > arr[i]){
      int idx = stk.top(); stk.pop();
      int r = i, l = stk.empty() ? 0 : stk.top();
      ans -= (ll)(r-idx) * (idx-l) * arr[idx];
    }
    stk.push(i);
  }
  cout<<ans<<"\n";
}