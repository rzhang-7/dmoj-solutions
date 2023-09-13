#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/nccc3j4s2

int n;
vector<pair<int, vector<int>>> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++){
    int median;
    vector<int> tmp;
    for(int j = 0, x; j<n; j++){
      cin>>x;
      tmp.push_back(x);
    }
    sort(tmp.begin(), tmp.end());
    median = (n & 1) ? tmp[n>>1] : (tmp[n>>1] + tmp[(n>>1)-1])>>1;
    v.push_back({median, tmp});
  }
  sort(v.begin(),v.end());
  cout<<((n & 1) ? v[n>>1].first : (v[n>>1].first + v[(n>>1)-1].first)>>1)<<"\n";
}