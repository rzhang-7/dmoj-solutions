#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc22j5

int n, t, ans;
vector<pair<int,int>> a;

int main() {
  cin>>n>>t;
  for(int i = 1, x, y; i<=t; i++){
    cin>>x>>y;
    a.push_back({x,y});
  }
  a.push_back({0,0});
  a.push_back({n+1,n+1});
  for(int i = 0; i<(int)a.size(); i++){
    for(int j = i+1; j<(int)a.size(); j++){
      int l = min(a[i].first, a[j].first);
      int r = max(a[i].first, a[j].first);
      int width = r - l - 1;
      vector<int> mid = {0, n+1};
      for(int k = 0; k<(int)a.size(); k++){
        if(a[k].first > l && a[k].first < r){
          mid.push_back(a[k].second);
        }
      }
      sort(mid.begin(), mid.end());
      for(int k = 1; k < (int)mid.size(); k++){
        int height = mid[k] - mid[k-1] - 1;
        ans = max(ans, min(width, height));
      }
    }
  }
  cout<<ans<<"\n";
}