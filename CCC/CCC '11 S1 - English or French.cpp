#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc11s1

int n;
int s = 0, t = 0;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i=0;i<=n;i++){
    string str;
    getline(cin,str);
    for(unsigned j = 0; j<str.length();j++){
      if(str[j] == 'S' || str[j] == 's') s++;
      else if(str[j] == 'T' || str[j] == 't') t++;
    }
  }
  if(t>s) cout<<"English"<<"\n";
  else cout<<"French"<<"\n";
}