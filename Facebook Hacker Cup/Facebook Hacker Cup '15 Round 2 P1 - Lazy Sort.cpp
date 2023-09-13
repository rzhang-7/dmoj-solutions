#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/fhc15c2p1

bool f(deque<int> a, deque<int> b){
  while(!a.empty()){
    if(a.front() == b.front()-1){
      b.push_front(a.front());
      a.pop_front();
    } else if(a.front() == b.back()+1){
      b.push_back(a.front());
      a.pop_front();
    } else if(a.back() == b.back()+1){
      b.push_back(a.back());
      a.pop_back();
    } else if(a.back() == b.front()-1){
      b.push_front(a.back());
      a.pop_back();
    }
    else break;
  }
  return a.empty();
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 1; i<=t; i++){
    int n;
    deque<int> a, b;
    cin>>n;
    for(int j = 1, x; j<=n; j++){
      cin>>x;
      a.push_back(x);
    }
    b.push_back(a.front());
    a.pop_front();
    bool x = f(a,b);
    a.push_front(b.back());
    b.pop_front();
    b.push_back(a.back());
    a.pop_back();
    bool y = f(a,b);
    cout<<"Case #"<<i<<": "<<(x||y ? "yes\n" : "no\n");
  }
}