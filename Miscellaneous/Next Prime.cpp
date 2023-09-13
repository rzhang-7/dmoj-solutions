#include <iostream>
using namespace std;

// https://dmoj.ca/problem/bf3

bool isPrime(long long x){
  for(long long i = 2; i*i<=x; i++){
    if(!(x%i)) return false;
  }
  return true;
}

int main() {
  long long n;
  cin>>n;
  if(n==1){cout<<2<<"\n"; return 0;}
  for(long long i = n; i<2*n; i++){
    if(isPrime(i)){
      cout<<i<<"\n";
      return 0;
    }
  }
}