#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc19j1

int n, a=0, b=0;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  for(int i=3; i>0; i--){
    cin>>n;
    a += n*i;
  }
  for(int i=3; i>0; i--){
    cin>>n;
    b += n*i;
  }
  if(a > b) cout<<"A"<<"\n";
  else if(a < b) cout<<"B"<<"\n";
  else cout<<"T"<<"\n";
}