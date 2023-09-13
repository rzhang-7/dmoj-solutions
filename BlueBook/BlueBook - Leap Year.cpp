#include <iostream>
using namespace std;

// https://dmoj.ca/problem/p307ex9

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 0; i<t; i++){
    int n;
    cin>>n;
    if(n%4==0 && n%100!=0) cout<<"1"<<"\n";
    else if(n%400==0) cout<<"1"<<"\n";
    else cout<<"0"<<"\n";
  }
}