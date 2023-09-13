#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc01j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int x, m; cin>>x>>m;
  for(int i = m-1; i>0; i--){
    if(x*i%m == 1){
      cout<<i<<"\n";
      return 0;
    }
  }
  cout<<"No such integer exists.\n";
}
