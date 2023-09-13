#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc22j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin>>str;
  for(int i = 0; i<(int)str.length(); i++){
    if(str[i] >= 'A') cout<<str[i];
    else if(str[i] == '-') cout<<" loosen ";
    else if(str[i] == '+') cout<<" tighten ";
    else {
      cout<<str[i];
      if(!isdigit(str[i+1])) cout<<"\n";
    }
  }
}