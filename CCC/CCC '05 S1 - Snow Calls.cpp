#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc05s1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 0; i<t; i++){
    string str, ans = "";
    cin>>str;
    for(char c : str){
      if(c >= '0' && c <= '9')
        ans += c;
      else if(c >= 'A' && c <= 'Z'){
        string except = "SVYZ";
        ans += (c - 'A')/3 + 2 - (except.find(c) != -1) + '0';
      }
    }
    for(int i = 0; i<10; i++){
      cout<<ans[i]<<(i==2||i==5?"-":"");
    }
    cout<<"\n";
  }
}