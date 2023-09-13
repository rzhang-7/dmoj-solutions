#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc13j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s;
  string sign = "IOSHZXN";
  cin>>s;
  for(int i = 0; i<(int)s.length(); i++){
    if(sign.find(s[i]) == -1){
      cout<<"NO\n";
      return 0;
    }
  }
  cout<<"YES\n";
}