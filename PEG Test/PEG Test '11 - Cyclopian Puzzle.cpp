#include <iostream>
using namespace std;

// https://dmoj.ca/problem/fur5

void hanoi(int n, char A, char B, char C){
  if(n==1){
    cout<<A<<C<<"\n";
  } else {
    hanoi(n-1, A, C, B);
    cout<<A<<C<<"\n";
    hanoi(n-1, B, A, C);
  }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  hanoi(n, 'A', 'B', 'C');
}