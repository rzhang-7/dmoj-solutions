#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ucc21p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string s; int t = 0;
  cin>>s;
  for(char c : s){
    if(c == '2') t++;
    else if(c == '5') t--;
  }
  cout<<t<<"\n";
}