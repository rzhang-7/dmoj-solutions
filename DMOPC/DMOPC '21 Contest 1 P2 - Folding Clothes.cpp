#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc21c1p2

int n, x;
vector<int> stk, moves;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>x;
  moves.push_back(1); stk.push_back(x);
  for(int i = 2; i<=n; i++){
    cin>>x;
    int p = lower_bound(stk.begin(), stk.end(), x) - stk.begin();
    if(p>0) moves.push_back(-p);
    moves.push_back(p+1);
    stk.insert(stk.begin() + p, x);
  }
  moves.push_back(-n);
  cout<<moves.size()<<"\n";
  for(int x : moves) cout<<x<<"\n";
}