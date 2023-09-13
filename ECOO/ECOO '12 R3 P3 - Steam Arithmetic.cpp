#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/ecoo12r3p3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i<10; i++){
    string str;
    stack<int> stk;
    getline(cin, str);
    for(int i = str.length()-1; i>=0; i--){
      if(str[i] == ' ' || str[i] == '(' || str[i] == ')') continue;
      if(isdigit(str[i])){
        stk.push(str[i]-'0');
      }
      else {
        int op1 = stk.top(); stk.pop();
        int op2 = stk.top(); stk.pop();
        if(str[i] == '+') stk.push(op1+op2);
        if(str[i] == '-') stk.push(op1-op2);
        if(str[i] == '*') stk.push(op1*op2);
        if(str[i] == 'q') stk.push(op1/op2);
        if(str[i] == 'r') stk.push(op1%op2);
      }
    }
    cout<<stk.top()<<"\n";
  }
}