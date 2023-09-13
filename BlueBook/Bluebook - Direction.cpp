#include <iostream>
using namespace std;

// https://dmoj.ca/problem/p108ex8

int n,d;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n--){
    cin>>d;
    if(d >= 315 || d <= 45) cout<<"N"<<"\n";
    else if(d <= 135) cout<<"E"<<"\n";
    else if(d <= 225) cout<<"S"<<"\n";
    else cout<<"W"<<"\n";
  }
}