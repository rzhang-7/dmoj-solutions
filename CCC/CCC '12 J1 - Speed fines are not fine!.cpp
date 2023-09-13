#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc12j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin>>n>>m;
  int lim = m - n;

  if(lim > 0){
    int fine;
    if(lim >= 1 && lim <= 20) fine = 100;
    else if(lim >= 21 && lim <= 30) fine = 270;
    else if(lim >= 31) fine = 500;
    cout<<"You are speeding and your fine is $"<<fine<<".\n";
  }
  else cout<<"Congratulations, you are within the speed limit!\n";
}