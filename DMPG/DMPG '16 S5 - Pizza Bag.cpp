#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmpg16s5

const int MM = 2e5+1;

int n, k;
ll ans, psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0; i<n; i++){
    cin>>psa[i];
  }
  for(int i = n; i<n+k; i++){
    psa[i] = psa[i%n];
  }
  for(int i = 0; i<n+k; i++){
    psa[i] += (i ? psa[i-1] : 0);
  }
  deque<pair<ll,ll>> dq;
  for(int i = 0; i<n+k; i++){
    while(i > k && !dq.empty() && dq.front().second < i-k){
      dq.pop_front();
    }
    while(!dq.empty() && dq.back().first > psa[i]){
      dq.pop_back();
    }
    dq.push_back({psa[i],i});
    ans = max(ans, psa[i]-dq.front().first);
  }
  cout<<ans<<"\n";
}