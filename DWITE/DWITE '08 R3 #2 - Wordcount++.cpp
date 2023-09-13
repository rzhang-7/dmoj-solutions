#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dwite08c3p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<5; i++){
    int cnt = 0, ans = 0;
    string str;
    getline(cin, str);
    for(char c : str){
      if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        cnt++;
      else {
        if(cnt > 3) ans++;
        cnt = 0;
      }
    }
    if(cnt > 3) ans++;
    cout<<ans<<"\n";
  }
}