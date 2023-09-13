#include <iostream>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/mwc15c2p2

const int MM = 1e6+1;

int n, ans[MM], arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  stack<int> stk;
  for(int i = 1; i<=n; i++){
    while(!stk.empty() && arr[i] >= arr[stk.top()]){
      stk.pop();
    }
    ans[i] = stk.empty() ? i-1 : i-stk.top(); 
    stk.push(i);
  }
  for(int i = 1; i<=n; i++){
    cout<<ans[i]<<" \n"[i==n];
  }
}
// 1 1 1 1 1

//
// 4
// 4
// 5
// 7
