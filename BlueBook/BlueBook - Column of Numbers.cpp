#include <iostream>
using namespace std;

// https://dmoj.ca/problem/p140ex3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string n;
  cin>>n;
  for(int i = n.length()-1; i>=0; i--) cout<<n[i]<<"\n"; 
}
/*
  while(n!=0){
    cout<<n%10<<"\n";
    n/=10;
  }
*/