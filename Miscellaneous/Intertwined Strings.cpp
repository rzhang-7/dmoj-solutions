#include <iostream>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/ul2

unordered_set<string> ans;

void f(string a, string b, string str){
  if(a.empty() && b.empty()){
    ans.insert(str);
    return;
  }  
  if(!a.empty()) f(a.substr(1), b, str+a[0]);
  if(!b.empty()) f(a, b.substr(1), str+b[0]);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string a, b, str = "";
  cin>>a>>b;
  f(a,b,str);
  for(string s : ans) cout<<s<<"\n";
}