#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc05j5

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  vector<string> v;
  string str;
  for(cin>>str; str != "X"; cin>>str){
    v.push_back(str);
  }    
  for(string s : v){
    while(true){
      int a = s.find("ANA");
      int b = s.find("BAS");
      if(a == -1 && b == -1) break;
      if(a != -1) s.replace(a, 3, "A");
      else if(b != -1) s.replace(b, 3, "A");
    }
    cout<<(s == "A" ? "YES\n" : "NO\n");
  }
}