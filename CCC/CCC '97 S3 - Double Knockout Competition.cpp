#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc97s3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  cin>>t;
  for(int i = 0; i<t; i++){
    cin>>n;
    int ud = n, ol = 0, elim = 0, cnt = 0;
    while(true){
      cout<<"Round "<<cnt<<": "<<ud<<" undefeated, "<<ol<<" one-loss, "<<elim<<" eliminated\n";
      if(ud == 0 && ol == 1) break; 
      if(ud == 1 && ol == 1){
        ud = 0;
        ol = 2;
      } else {
        elim += ol/2;
        ol = ol - ol/2 + ud/2;
        ud -= ud/2;
      }
      cnt++;
    }
    cout<<"There are "<<cnt<<" rounds.\n";
    if(i != t-1) cout<<"\n";
  }
}