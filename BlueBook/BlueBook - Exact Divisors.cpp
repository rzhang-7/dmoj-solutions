#include <iostream>
using namespace std;

// https://dmoj.ca/problem/p154ex8

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 1; i<=n/2; i++){
    if(n%i == 0) cout<<i<<"\n";
  }
  cout<<n<<"\n";
}