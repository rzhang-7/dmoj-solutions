#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc13s1

int y;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>y;
  y += 1;
  while(true){
    string s = to_string(y);
    bool ft = false;
    for(int i = 0; i < s.size(); i++){
      for(int j = i+1; j < s.size(); j++){
        if(s[j] == s[i]) ft = true;   
        else continue;
      }
    }
    if(!ft){
      cout<<y<<"\n";
      break;
    } 
    else y++;
  }
}

/*********************************************************

Compares each digit to each other. If it finds a not distinct digit, input is increased by 1.

*********************************************************/