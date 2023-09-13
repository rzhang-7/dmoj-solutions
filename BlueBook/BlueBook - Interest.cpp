#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/p124ex3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  float n,m;
  int y;
  cin>>n>>m>>y;
  float p = n;
  cout<<fixed<<showpoint;
  cout<<setprecision(2);
  for(int i = 0; i <= y; i++){
    cout<<i<<" "<<n<<"\n";
    n = p*pow((1 + m*0.01),i+1);
  }
}