#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/coci16c2p3

// if first and last element are equal, they are removed
// if first is greater than last, last is combined with second last, answer incremented by 1
// if last is greater than first, first is combined with second, answer incremented by 1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin>>n;
  deque<int> q;
  for(int i = 0; i<n; i++){
    int p; cin>>p;
    q.push_back(p);
  }
  while(q.size() > 1){
    int a = q.front(), b = q.back();
    if(a == b){
      q.pop_front();
      q.pop_back();
    } else if(a > b) {
      q.pop_back();
      int c = q.back(); q.pop_back();
      q.push_back(b + c); 
      ans++;
    } else {
      q.pop_front();
      int c = q.front(); q.pop_front();
      q.push_front(a + c);
      ans++;
    }
  }
  cout<<ans<<"\n";
}