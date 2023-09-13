#include <iostream>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/dwite07c2p4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 5; i++){
    string s;
    stack<char> b;
    bool bal = true;
    cin>>s;
    for(auto c : s){
      if(c == '(' || c == '{' || c == '['){
        b.push(c);
      } 
      else if(c == ')'){
        if(!b.empty()){
          if(b.top() != '('){
            bal = false;
            break;
          }
          b.pop();
        } else {
          bal = false;
          break;
        }
      }
      else if(c == '}'){
        if(!b.empty()){
          if(b.top() != '{'){
            bal = false;
            break;
          }
          b.pop();
        } else {
          bal = false;
          break;
        }
      }
      else if(c == ']'){
        if(!b.empty()){
          if(b.top() != '['){
            bal = false;
            break;
          }
          b.pop();
        } else {
          bal = false;
          break;
        }
      }
    }
    if(!b.empty() && (b.top() == '(' || b.top() == '{' || b.top() == '[')){
      bal = false;
    }
    bal ? cout<<"balanced\n" : cout<<"not balanced\n";
  }
}