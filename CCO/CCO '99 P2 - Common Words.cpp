#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/cco99p2

bool cmp(pair<string, int> x, pair<string, int> y){
  return x.second > y.second;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  while(n--){
    int m, k;
    vector<pair<string, int>> v;
    map<string, int> m1;
    cin>>m>>k;
    for(int i = 0; i<m; i++){
      string str;
      cin>>str;
      m1[str]++;
    }
    for(auto x : m1) v.push_back(x);
    sort(v.begin(), v.end(), cmp);    
    cout<<k;
    if(k%10 == 1 && k%100 != 11)
      cout<<"st";
    else if(k%10 == 2 && k%100 != 12)
      cout<<"nd";
    else if(k%10 == 3 && k%100 != 13)
      cout<<"rd";
    else
      cout<<"th";
    cout<<" most common word(s):\n";
    
    int cnt = 1;
    if(k == 1) cout<<v[0].first<<"\n";
    for(int i = 1; i<(int)v.size(); i++){
      if(v[i].second != v[i-1].second) cnt=i+1;
      if(cnt == k) cout<<v[i].first<<"\n";
    }
    cout<<"\n";
  }
}