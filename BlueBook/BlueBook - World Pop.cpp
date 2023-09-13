#include <iostream>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/p124ex4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  double p;
  int y,f;
  long long n;
  cin>>p>>y>>n>>f;
  long long ans = ceil(n*pow(1 + p*0.01, f-y));
  cout<<ans<<"\n";
}