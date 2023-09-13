#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/usaco21febs3

const int MM = 502;

int n, a[MM][MM], b[MM][MM];

ll f(int a[][MM]){
  vector<int> hist(MM);
  ll ans = 0;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      hist[j] = a[i][j] ? hist[j]+1 : 0;
    }
    stack<pair<int,int>> stk; 
    ll rect = 0;
    for(int j = 1; j<=n; j++){
      int w = 1;
      while(!stk.empty() && stk.top().first > hist[j]){
        pair<int,int> t = stk.top();
        stk.pop();
        rect -= (ll)(t.first-hist[j])*t.second;
        w += t.second;
      }
      rect += hist[j]; ans += rect;
      stk.push({hist[j], w});
    }
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 1; i<=n; i++){
    for(int j = 1, x; j<=n; j++){
      cin>>x;
      a[i][j] = x >= 100;
      b[i][j] = x > 100;
    }
  }
  cout<<f(a) - f(b)<<"\n";
}