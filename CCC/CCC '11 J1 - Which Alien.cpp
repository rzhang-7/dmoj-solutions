#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc11j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a, e;
  cin>>a>>e;
  
  if(a >= 3 && e <= 4){
    cout<<"TroyMartian\n";
  }
  if(a <= 6 && e >= 2){
    cout<<"VladSaturnian\n";
  }
  if(a <= 2 && e <= 3){
    cout<<"GraemeMercurian\n";
  }
}