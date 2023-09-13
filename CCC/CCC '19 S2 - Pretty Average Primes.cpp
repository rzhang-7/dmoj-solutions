#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc19s2

bool isPrime(int x){
  for(int i = 2; i*i <= x; i++){
    if(x%i == 0) return false;
  }
  return true;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int i = 0; i < t; i++){
    int n, a, b; bool found = false;
    cin>>n;
    for(int j = 2; j <= 2*n && !found; j++){
      a = j; b = 2*n-j;
      if(isPrime(a) && isPrime(b) && a+b == 2*n){
        cout<<a<<" "<<b<<"\n";
        found = true;
      } 
    }
  }
}