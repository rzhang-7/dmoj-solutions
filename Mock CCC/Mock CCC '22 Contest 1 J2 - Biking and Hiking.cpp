#include <iostream>
using namespace std;

// https://dmoj.ca/problem/mccc3j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, k, ans = 0;
  string str;
  cin>>n>>k>>str;
  for(char c : str){
    if(c == 'U'){
      k -= k > 0;
    }
    else if(c == 'D'){
      k++;
    }
    if(k == 0) ans++;
  }
  cout<<ans<<"\n";
}