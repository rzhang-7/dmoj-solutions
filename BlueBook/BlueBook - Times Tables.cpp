#include <iostream>
using namespace std; 

// https://dmoj.ca/problem/p118ex4

int main() {
  int n, ans;
  cin>>n;
  for(int i = 1; i <= n; i++){
    ans = n*i;
    cout<<n<<" X "<<i<<" = "<<ans<<"\n";
  }
}