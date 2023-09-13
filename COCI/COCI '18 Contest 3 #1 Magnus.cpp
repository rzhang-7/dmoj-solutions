#include <iostream>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/coci18c3p1

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  int c = 0;    
  unordered_set<char> honi;
  cin>>str;
  for(int i = 0; i < str.length(); i++){
    if(str[i] == 'H') honi.insert(str[i]);
    else if(str[i] == 'O' && honi.size() == 1) honi.insert(str[i]);
    else if(str[i] == 'N' && honi.size() == 2) honi.insert(str[i]);
    else if(str[i] == 'I' && honi.size() == 3){
      honi.insert(str[i]);
      c++;
      honi.clear();
    }
  }
  cout<<c<<"\n";
}