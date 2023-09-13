#include <iostream>
using namespace std;

// https://dmoj.ca/problem/usaco21janb2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, c, even = 0, odd = 0;
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>c;
    c % 2 == 0 ? even++ : odd++;
  }
  while(even < odd){
    even++;
    odd -= 2;
  } 
  if(odd+1 < even) even = odd + 1;
  cout<<odd+even<<"\n";  
}