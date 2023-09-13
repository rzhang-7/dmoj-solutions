#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc15j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int m,d;
  cin>>m>>d;
  if(m < 2) cout<<"Before\n";
  else if(m > 2) cout<<"After\n";
  else if(m == 2){
    if(d < 18) cout<<"Before"<<"\n";
    else if(d > 18) cout<<"After"<<"\n";
    else cout<<"Special\n";
  }
}