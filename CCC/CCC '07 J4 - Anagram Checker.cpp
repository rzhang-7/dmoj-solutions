#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/ccc07j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str1, str2;
  map<char, int> l,m;
  getline(cin, str1);
  getline(cin, str2);  
  for(int i = 0; i < (int)str1.length(); i++){
    if(str1[i] == ' ') continue;
    
    if(l.count(str1[i]) == 0){
      l[str1[i]] = 1;
    }
    else {
      l[str1[i]]++;
    }
  }
  for(int i = 0; i < (int)str2.length(); i++){
    if(str2[i] == ' ') continue;
    
    if(m.count(str2[i]) == 0){
      m[str2[i]] = 1;
    }
    else {
      m[str2[i]]++;
    }
  }
  l == m ? cout<<"Is an anagram.\n" : cout<<"Is not an anagram.\n";
}