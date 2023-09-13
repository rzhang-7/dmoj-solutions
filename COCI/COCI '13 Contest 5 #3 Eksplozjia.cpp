#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/coci13c5p3

const int MM = 1e6+1;

int bgn[MM], nds[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str, ex, ans = "";
  cin>>str>>ex;
  if(ex.size() == 1){
    for(int i = 0; i<(int)str.size(); i++){
      if(str[i] == ex[0]){
        bgn[i]++; nds[i]++;
      }
    }
  } else {
    stack<pair<int,int>> stk;
    for(int i = 0; i<(int)str.size(); i++){
      if(str[i] == ex[0]) {
        stk.push({i,1});
      } else {
        if(!stk.empty()){
          pair<int,int> tmp = stk.top(); stk.pop();
          if(str[i] != ex[tmp.second]){
            while(!stk.empty())stk.pop();
          } else {
            tmp.second++;
            if(tmp.second == (int)ex.size()) {
              bgn[tmp.first]++; nds[i]++;
            } else {
              stk.push({tmp.first, tmp.second});
            }
          }
        }
      }
    }
  }
  int e = 0, rem = 0;
  for(int i = 0; i<(int)str.size(); i++){
    e += bgn[i];
    if(e) ans += '*';
    else {rem++; ans += str[i];}
    e -= nds[i];
  }
  if(rem){
    for(int i = 0; i<(int)ans.size(); i++){
      if(ans[i] != '*') cout<<ans[i];
    }
  }
  else cout<<"FRULA";
  cout<<"\n";
}

// Naive approach (individual search/delete, slow)
  // string m, ex;
  // cin>>m>>ex;
  // int index = m.find(ex);
  // while(index != -1){
  //   m.erase(index, ex.length());
  //   index = m.find(ex);
  // }
  // cout<<(m == "" ? "FRULA" : m)<<"\n";