#include <iostream>
using namespace std;

// https://dmoj.ca/problem/aac1p1

const double PI = 3.14;

int s;
double r;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>s>>r;
  cout<<(s*s > PI*r*r ? "SQUARE\n" : "CIRCLE\n");
}