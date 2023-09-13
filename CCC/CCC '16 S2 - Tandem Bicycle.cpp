#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc16s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,s,b;
  int speed = 0;
  vector<int> d,p;
  cin>>s>>n;  
  for(int i = 0; i<n; i++){
    cin>>b;
    d.push_back(b);
  }
  for(int i = 0; i<n; i++){
    cin>>b;
    p.push_back(b);
  }
  sort(d.begin(),d.end());
  s == 1 ? sort(p.begin(),p.end()) :  sort(p.begin(),p.end(),greater<>());

  for(int i = 0; i<n; i++){
    speed += max(d[i],p[i]);
  }
  cout<<speed<<"\n";
}  

  // 5 1 4
  // 6 2 4

  // 1
  // 1 4 5
  // 2 4 6
  
  // 2
  // 1 4 5
  // 6 4 2

  // speed is max() of each column