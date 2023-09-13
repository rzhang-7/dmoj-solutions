#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc18j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if((a == 8 || a == 9) && (d == 8 || d == 9) && b==c){
    cout<<"ignore"<<"\n";
  }
  else cout<<"answer"<<"\n";
}