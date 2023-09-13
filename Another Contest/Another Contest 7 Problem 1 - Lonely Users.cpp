#include <iostream>
using namespace std;

// https://dmoj.ca/problem/acc7p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 0, n; i<t; i++){
    cin>>n;
    cout<<n-(n!=2)<<"\n";
  }
}