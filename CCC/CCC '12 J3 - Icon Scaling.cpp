#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc12j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 0; i < n; i++){
    cout<<string(n, '*');
    cout<<string(n, 'x');
    cout<<string(n, '*');
    cout<<"\n";
  }
  for(int i = 0; i < n; i++){
    cout<<string(n, ' ');
    cout<<string(2*n, 'x');
    cout<<"\n";
  }
  for(int i = 0; i < n; i++){
    cout<<string(n, '*');
    cout<<string(n, ' ');
    cout<<string(n, '*');
    cout<<"\n";
  }
}