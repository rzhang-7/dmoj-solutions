#include <iostream>
using namespace std;

// https://dmoj.ca/problem/cheerio3p2

int n, ans, ammo1, ammo2;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++){
    char c;
    cin>>c;
    if(c=='R'){
      ammo2++;
      if(ammo1){
        ans++;
        ammo1--;
      }
      else {
        ammo1++;
      }
    } else if(c=='B'){
      ammo1++;
    } else {
      if(ammo2){
        ammo2--;
      } else if(ammo1) {
        ans++;
        ammo1--;
      } else {
        ammo1++;
      }
    }
  }
  cout<<ans<<"\n";
}