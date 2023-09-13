#include <iostream>
using namespace std;

// https://dmoj.ca/problem/yac6p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m, cnt = 2, deg = 1;
  cin>>n>>m;
  for(int i = 2; i<=n; i++, m--)
    cout<<1<<" "<<i<<"\n";
  while(m--){
    if(cnt+deg>n){
      cnt++;
      deg = 1;
    }
    cout<<cnt<<" "<<cnt+deg<<"\n";
    deg++;
  }
}