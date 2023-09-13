#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc15j3

int main() {
  cin.sync_with_stdio(0); 
  cin.tie(0);
  string str, s;
  cin>>str;
  string vowel = "aeiou";
  for(int i = 0; i < (int)str.length(); i++){
    int index = vowel.find(str[i]);
    if(index == -1){
      s += str[i];
      
      if(str[i]<='c') s += 'a';
      else if(str[i]<='g') s += 'e';
      else if(str[i]<='l') s += 'i';
      else if(str[i]<='r') s += 'o';
      else if(str[i]<='z') s += 'u';
      
      char third = str[i] + 1;
      if(third == 'e' || third == 'i' || third == 'o' || third == 'u') third++;
      else if(str[i] == 'z') third = 'z';
      s += third;
    }
    else s += str[i];
  }
  
  cout<<s<<endl;
}