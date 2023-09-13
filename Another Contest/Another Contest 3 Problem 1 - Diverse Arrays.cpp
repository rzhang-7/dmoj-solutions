#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/acc3p1

const int MM = 1e6+1;

int n, k, arr[MM];
ll ans;
unordered_map<int,int> mp;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 1; i<=n; i++){
    cin>>arr[i];
  }
  int distinct = 1;
  mp[arr[1]]++;
  
  for(int lft = 1, rit = 1; rit<=n;){
    if(distinct >= k){
      mp[arr[lft]]--;
      if(mp[arr[lft++]]==0) distinct--;
      ans += n - rit + 1;
    } else {
      rit++;
      if(mp[arr[rit]]==0) distinct++;
      mp[arr[rit]]++;
    }
  }
  cout<<ans<<"\n";
}
// 1 3 3 2 3, k = 2
// lft = 2, rit = 4;
// distinct = 2
// ans = 4
// 1 : 0
// 3 : 2
// 2 : 1