#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dmopc21c5p2

// any triangular number (sum of 1 to n) except 3 (n = 2) is composite

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  switch(n){
    case 1:
      cout<<1<<"\n";
      break;
    case 2:
      cout<<-1<<"\n";
      break;
    default:
      cout<<"1 3 2"<<" \n"[n==3];
      for(int i = 4; i<=n; i++){
        cout<<i<<(i==n?"\n":" ");
      }
      break;
  }
}