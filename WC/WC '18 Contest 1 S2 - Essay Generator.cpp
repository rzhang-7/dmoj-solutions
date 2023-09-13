#include <iostream>
using namespace std;

// https://dmoj.ca/problem/wc18c1s2

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int w, cnt = 0;
  cin>>w;
  for(char i = 'a'-1; i<='z'; i++){
    for(char j = 'a'; j<='z'; j+=(cnt>26)){
      for(char k = 'a'; k<='z'; k++){
        if(cnt == w) {cout<<"\n"; return 0;}
        if(cnt >= 702) cout<<i;
        if(cnt >= 26) cout<<j;
        cout<<k<<" ";
        cnt++;
      }
    }
  }
}