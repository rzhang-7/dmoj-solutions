#include <iostream>
using namespace std;

// https://dmoj.ca/problem/vmss7wc16c1p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n; cin>>n;
  while(n%2==0){
    cout<<2<<"\n";
    n/=2;
  }
  for(int i = 3; i*i<=n; i+=2){
    while(n%i==0){
      cout<<i<<"\n";
      n/=i;
    }
  }
  if(n>1) cout<<n<<"\n";
}