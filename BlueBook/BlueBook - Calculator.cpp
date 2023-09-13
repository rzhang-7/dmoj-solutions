#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/p309ex13

int toBase10(string n, int base){
  int cnt = 0, ans = 0;
  for(int i = n.length()-1; i>=0; i--){
    ans += (n[i]-'0') * pow(base,cnt);
    n.pop_back(); cnt++;
  }
  return ans;
}

string toBaseN(int n, int base){
  string ans = "";
  while(n != 0){
    ans += n%base + '0';
    n /= base;
  }
  if(ans == "") return "0";
  reverse(ans.begin(),ans.end());
  return ans;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int b1, b2, bf, x, y, ans = 0;
    string a, b;
    char op;
    cin>>b1>>a>>b2>>b>>op>>bf;
    x = toBase10(a, b1);
    y = toBase10(b, b2);
    if(op == '+') ans = x+y;
    else if(op == '-') ans = x-y;
    else if(op == '*') ans = x*y;
    else if(op == '/') ans = x/y;
    if(bf == 10) cout<<ans<<"\n";
    else cout<<toBaseN(ans, bf)<<"\n";
  }
}