#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc12j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string code, ans = "";
  cin>>n>>code;
  for(int i = 0; i<(int)code.length(); i++){
    int s = 3 * (i+1) + n;
    if(code[i] - s < 65){
      ans += 91 - (65 - (code[i] - s));
    } else {
      ans += code[i] - s;
    }
  }
  cout<<ans<<"\n";
}