#include <iostream>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/ccc15s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, temp = 0;
  cin>>n;
  stack<int> s;
  for(int i = 0; i < n; i++){
    int k;
    cin>>k;
    if(k == 0) s.pop();
    else s.push(k);
  }
  while(!s.empty()){
    temp += s.top();
    s.pop();
  }
  cout<<temp<<endl;
}