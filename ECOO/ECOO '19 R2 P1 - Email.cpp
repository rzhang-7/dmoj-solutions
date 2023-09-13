#include <iostream>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/ecoo19r2p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string s;
  for(int i = 0; i<10; i++){
    unordered_set<string> email;
    cin>>n;
    while(n--){
      string e;
      cin>>s;      
      int pIndex = s.find('+');
      int aIndex = s.find('@');
      if(pIndex == -1) pIndex = aIndex;
      for(int i = 0; i<s.length(); i++){
        if(i >= pIndex && i < aIndex) continue;
        int c = iswalnum(s[i]);
        if(c || s[i] == '@' || (s[i] == '.' && i > aIndex)){
          c = tolower(s[i]);
          e += c;
        }
      }
      email.insert(e);
    }
    cout<<email.size()<<"\n";
  }
}