#include <iostream>
using namespace std;

// https://dmoj.ca/problem/p108ex7

int n,m,cost=0;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  while(n--){
    cin>>m;
    if(m<=30) cost = 38;
    else if(m<=50) cost = 55;
    else if(m<=100) cost = 73;
    else if(m>100) cost = 73 + 24*((m-50-1)/50);
    cout<<cost<<"\n";
  }
}