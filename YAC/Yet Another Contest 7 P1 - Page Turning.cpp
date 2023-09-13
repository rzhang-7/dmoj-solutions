#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/yac7p1

const int MM = 1e6+1;

// first piece is odd, the rest is even, last are odd

int n; vector<pair<int,int>> even, odd;
vector<int> ans;
ll total;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  // int mx = -1;
  for(int i = 1, x; i<=n; i++){
    cin>>x;
    (x&1) ? odd.push_back({x,i}) : even.push_back({x,i});
    // if(!odd.empty() && odd.back() > mx)
    //   mx = odd.back();
  }
  if(odd.empty()){
    for(int i = 0; i<(int)even.size(); i++){
      total += even[i].first/2;
      ans.push_back(i+1);
    }
  } else if(even.empty()){
    for(int i = 0; i<(int)odd.size(); i++){
      total += odd[i].first/2;
      ans.push_back(i+1);
    }
  } else {
    // bool skip = true;
    // ans += mx;
    total += odd[0].first/2;
    ans.push_back(odd[0].second);
    for(pair<int,int> x : even){
      total += x.first/2 - 1;
      ans.push_back(x.second);
    }
    for(int i = 1; i<(int)odd.size(); i++){
      total += odd[i].first/2;
      ans.push_back(odd[i].second);
    }
  }
  cout<<total<<"\n";
  for(int x : ans) cout<<x<<" ";
  cout<<"\n";
}