#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ccc10s2

map<char,string> code;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n; string str, ans = "";
  cin>>n;
  for(int i = 0; i<n; i++){
    char c; string s;
    cin>>c>>s;
    code[c] = s;
  }
  cin>>str;
  while(str.length() != 0){
    for(auto x : code){
      if(str.find(x.second) == 0){
        ans += x.first;
        str.erase(0, x.second.length());
      }
    }
  }
  cout<<ans<<"\n";
}