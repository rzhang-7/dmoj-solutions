#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ecoo19r1p1

int n, m, d, ans;
map<int,int> event;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<10; i++){
    cin>>n>>m>>d;
    int s = n;
    for(int i = 1, x; i<=m; i++){
      cin>>x; event[x]++;
    }
    for(int i = 1; i<=d; i++){
      if(!s) {
        ans++; 
        s += n;
      }
      if(event[i]){
        s += event[i]; n += event[i];
      }
      s--;
    }
    cout<<ans<<"\n";
    event.clear(); ans = 0;
  }
}