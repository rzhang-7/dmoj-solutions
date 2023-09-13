#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc14j1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a, b, c;
  cin>>a>>b>>c;
  if(a + b + c == 180){
    if(a == b && b == c){
      cout<<"Equilateral\n";
    }
    else if(a == b || a == c || b == c){
      cout<<"Isosceles\n";
    }
    else{
      cout<<"Scalene\n";
    }
  }
  else cout<<"Error\n";
}