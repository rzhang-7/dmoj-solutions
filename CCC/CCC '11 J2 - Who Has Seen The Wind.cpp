#include <iostream>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/ccc11j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int h, m, a;
  cin>>h>>m;
  for(int i = 1; i <= m; i++){
    a = -6 * pow(i,4) + h * pow(i,3) + 2 * pow(i,2) + i;
    if(a<=0) {
      cout<<"The balloon first touches ground at hour:"<<"\n"<<i<<"\n";
      return 0;
    }
  }
  cout<<"The balloon does not touch ground in the given time."<<"\n";
}