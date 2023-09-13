#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/gfssoc2s2

int n, t;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>t;
  vector<pair<string,int>> v;
  for(int i = 0; i<n; i++){
    string s;
    int c;
    cin>>s>>c;
    v.push_back({s,c});
  }
  sort(v.begin(), v.end());
  for(int i = 0; i<n-2; i++){
    for(int j = i+1; j<n-1; j++){
      for(int k = j+1; k<n; k++){
        if(v[i].second + v[j].second + v[k].second <= t){
          cout<<v[i].first<<" "<<v[j].first<<" "<<v[k].first<<"\n";
        }
      }
    }
  }
}