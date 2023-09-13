#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc11s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, correct = 0;
  char q;
  vector<char> s,c;
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>q;
    s.push_back(q);
  }
  for(int i = 0; i<n; i++){
    cin>>q;
    c.push_back(q);
  }
  for(int i = 0; i<n; i++){
    if(s[i] == c[i]) correct++;
  }
  cout<<correct<<"\n";
}