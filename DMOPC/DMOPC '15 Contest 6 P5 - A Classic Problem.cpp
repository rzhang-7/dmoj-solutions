#include <iostream>
#include <deque>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/dmopc15c6p5

const int MM = 3e6+1;

int n, k, arr[MM];
ll ans;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 1; i<=n; i++) cin>>arr[i];
  deque<int> mi, mx;
  for(int l = 1, r = 1; r<=n; r++){
    while(!mi.empty() && mi.back() > arr[r]) mi.pop_back();
    while(!mx.empty() && mx.back() < arr[r]) mx.pop_back();
    mi.push_back(arr[r]); mx.push_back(arr[r]);
    while(mx.front() - mi.front() > k){
      if(mx.front() == arr[l]) mx.pop_front();
      if(mi.front() == arr[l]) mi.pop_front();
      l++;
    }
    ans += r-l+1;
  }
  cout<<ans<<"\n";
}