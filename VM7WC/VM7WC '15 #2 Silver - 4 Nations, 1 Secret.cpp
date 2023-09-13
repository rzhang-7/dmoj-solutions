#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/vmss7wc15c2p2

const int MM = 25002, base = 137, MOD = 1e9+7;

int n, ans = 1, ansL, start, pos;
string s;
ll pre[MM], suf[MM], pw[MM];

ll sq(int l, int r){
  return (suf[l] - suf[r+1]*pw[r-l+1] % MOD + MOD) % MOD;
}

ll pq(int l, int r){ 
  return (pre[r] - pre[l-1]*pw[r-l+1] % MOD + MOD) % MOD;
}

bool check(int len){
  for(int i = 1; i+len-1 <= n; i++){
    if(pq(i,i+len-1) == sq(i, i+len-1)){
      pos = i;
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>s;
  pw[0] = 1;
  for(int i = 1; i<=n; i++){
    pre[i] = (pre[i-1] * base + s[i-1]) % MOD;
    pw[i]= pw[i-1]*base % MOD;
  }
  for(int i = n; i>=1; i--)
    suf[i] = (suf[i+1] * base + s[i-1]) % MOD;
  vector<int> len[2];
  for(int i = 2; i<=n; i++){
    len[i%2].push_back(i);
  }
  for(int k = 0; k<2; k++){
    int lo = 0, hi = (int)len[k].size()-1, best = -1;
    while(lo <= hi){
      int mid = (lo+hi)/2;
      if(check(len[k][mid])){
        best = mid;
        start = pos;  
        lo = mid + 1;
      }
      else hi = mid-1;
    }
    if(best != -1 && len[k][best] > ans){
      ans = len[k][best];
      ansL = start;
    }
  }
  cout<<s.substr(ansL-1, ans)<<"\n"<<ans<<"\n";
}