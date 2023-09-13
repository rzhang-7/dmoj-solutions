#include <iostream>
using namespace std;

// https://dmoj.ca/problem/dwite07c1p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  if(n<2){
    cout<<"not\n";
  } else {
    for(int i = 2; i*i<=n; i++){
      if(n%i == 0){ 
        cout<<"not\n";
        return 0;
      }
    }
    cout<<"prime\n";
  }
}