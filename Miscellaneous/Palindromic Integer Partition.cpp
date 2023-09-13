#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/backtrack1

int n;
ll memo[100];

ll f(int n){
  if(memo[n] != 0) return memo[n];
  if(n <= 1) return memo[n]=1;
  ll ans = 1;
  for(int i=n-2; i>=0; i-=2){
    ans += f(i);
  }
  return memo[n] = ans;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cout<<f(n)<<"\n";
}