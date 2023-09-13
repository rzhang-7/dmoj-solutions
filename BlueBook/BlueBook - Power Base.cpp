#include <iostream>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/p124ex5

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, p;
  float x;
  cin>>n;
  while(n--){
    cin>>x>>p;
    printf("%.2f\n", pow(x,p));
  }
}