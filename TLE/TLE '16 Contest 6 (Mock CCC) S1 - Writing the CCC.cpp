#include <iostream>
#include <queue>
#include <map>
using namespace std;

// https://dmoj.ca/problem/tle16c6s1

// Aflatoxin B1
// https://dmoj.ca/problem/tle16c6s1/editorial

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t,n;
  string type, q;
  map<string, int> order;
  map<int,queue<int>> ans;
  
  cin>>t;
  for(int i = 1; i<=t; i++){
    cin>>type;
    order[type] = i;
  }
  cin>>n;
  for(int i = 1; i<=n; i++){
    cin>>q;
    ans[order[q]].push(i);
  }
  for(auto x: ans){
    if(x.second.size() > 1){
      while(x.second.size() != 0){
        cout<<x.second.front()<<"\n";
        x.second.pop();
      }
    } else {
      cout<<x.second.front()<<"\n";
    }
  }
}