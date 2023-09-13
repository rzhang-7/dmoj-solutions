#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/canada21p3

int t;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--){
    stack<char> stk;
    string n;
    vector<char> ans;
    int k, cnt = 0;
    cin>>n>>k;
    stk.push(n[0]);
    for(int i = 1; i<(int)n.length(); i++){
      while(!stk.empty() && stk.top() > n[i] && cnt < k){
        ans.push_back(stk.top());
        stk.pop();
        cnt++;
      }
      stk.push(n[i]);
    }
    sort(ans.begin(), ans.end());
    while(!stk.empty() && cnt < k && !ans.empty()){
      if(stk.top() > ans[0]){
        ans.push_back(stk.top());
        stk.pop();
        cnt++;
      } else break;
    }
    sort(ans.begin(), ans.end());
    string tmp;
    while(!stk.empty()){
      tmp += stk.top(); stk.pop();
    }
    reverse(tmp.begin(), tmp.end());
    cout<<tmp;
    for(char c : ans){
      cout<<c;
    } cout<<"\n";
  }
}