#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/smac08c1p3

const int MM = 1e6+1;
const int INF = 1e9;

int n, d, arr[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>d;
  vector<int> dp(n, INF);
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }
  dp[0] = arr[0];
  deque<int> dq(1,0);
  for(int i = 1; i<n; i++){
    while(!dq.empty() && dq.front() < i-d) dq.pop_front();
    dp[i] = dp[dq.front()] + arr[i];
    while(!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();
    dq.push_back(i);
  }
  cout<<dp[n-1]<<"\n";
}