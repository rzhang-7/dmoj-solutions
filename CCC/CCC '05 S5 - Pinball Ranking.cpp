#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/ccc05s5

const int MM = 1e5+1;

int n, arr[MM], bit[MM], rnk;
ll ans;
map<int,int> mp;

void update(int i, int val){
  for(; i<MM; i+=i&-i)
    bit[i] += val;
}

int sum(int i){
  int ans = 0;
  for(; i>0; i-=i&-i){
    ans += bit[i];
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>arr[i]; mp[arr[i]] = 0;
  }
  for(auto &x : mp){
    x.second = ++rnk;
  }
  for(int i = 1; i<=n; i++){
    ans += i-sum(mp[arr[i]]);
    update(mp[arr[i]], 1);
  }
  cout<<fixed<<setprecision(9)<<(double)ans/n<<"\n";
}