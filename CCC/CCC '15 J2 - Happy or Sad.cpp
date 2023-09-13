#include <iostream>
#include <string>
using namespace std;

// https://dmoj.ca/problem/ccc15j2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string line;
  int h = 0, s = 0;
  getline(cin, line);
  string str = line;
  int hIndex = line.find(":-)");
  int sIndex = line.find(":-(");
  while(hIndex >= 0){
    str = str.substr(hIndex + 1);
    hIndex = str.find(":-)");
    h++;
  }
  str = line;
  while(sIndex >= 0){
    str = str.substr(sIndex + 1);
    sIndex = str.find(":-(");
    s++;
  }
  if(h>s) cout<<"happy\n";
  else if(h<s) cout<<"sad\n";
  else if(h == 0) cout<<"none\n";
  else cout<<"unsure\n";
}