#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc20c5p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s, t; cin>>s>>t;
  int ans = 0;
  if(s.length() > t.length()){
    while(s.length() != t.length()){
      s.pop_back(); ans++;
    }
  }
  int idx = 0;
  do{
    idx += s[idx] == t[idx];
  } while(s[idx] == t[idx] && idx < (int)s.length());
  ans += (s.length() - idx)*2 + t.length() - s.length();
  cout<<ans<<"\n";
}