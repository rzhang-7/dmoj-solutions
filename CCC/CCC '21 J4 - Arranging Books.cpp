#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc21j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  int l = 0, m = 0, swapL = 0, swapM = 0, lm = 0, ml = 0;
  cin>>str;
  for(char c : str){
    if(c == 'M') m++;
    if(c == 'L') l++;
  }
  for(int i = 0; i<l; i++){
    if(str[i] != 'L') swapL++;
    if(str[i] == 'M') ml++;
  }
  for(int i = l; i<l+m; i++){
    if(str[i] != 'M') swapM++;
    if(str[i] == 'L') lm++;
  }
  cout<<swapL + swapM - min(lm, ml)<<"\n";
}