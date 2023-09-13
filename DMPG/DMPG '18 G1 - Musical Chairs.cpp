#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/dmpg18g1

int n, k;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  vector<bool> taken(n+1, 1);
  for(int i = 0, x; i<k; i++){
    cin>>x;
    taken[x] = 0;
  }
  vector<int> pos(n+1);
  for(int i = 1, x; i<=k+1; i++){
    cin>>x;
    pos[x] = i;
  }
  stack<int> stk;
  for(int i = 1; i<=n; i++){
    if(pos[i]){
      stk.push(pos[i]);
    }
    if(!taken[i] && !stk.empty()){
      taken[i] = 1;
      stk.pop();
    }
  }
  for(int i = 1; i<=n ;i++){
    if(!taken[i] && !stk.empty()){
      taken[i] = 1;
      stk.pop();
    }
  }
  cout<<stk.top()<<"\n";
}