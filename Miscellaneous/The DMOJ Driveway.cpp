#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/stack1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t, m;
  cin>>t>>m;
  deque<string> dq;
  for(int i = 0; i<t; i++){
    string x, c;
    cin>>x>>c;
    if(c == "in"){
      dq.push_back(x);
    } else {
      if(dq.back() == x) dq.pop_back();
      else if(dq.front() == x && m > 0){dq.pop_front(); m--;}
    }
  }
  for(auto x : dq) cout<<x<<"\n";
}