#include <iostream>
#include <stack>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/postfix

bool isNum(const string& s){
  auto it = s.begin();
  while(it != s.end() && isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str, buf;
  stack<double> num; 
  getline(cin, str);
  vector<string> split;
  stringstream ss(str);
  
  while(ss>>buf){ // splits string into vector
    split.push_back(buf);
  } 
  
  for(int i = 0; i<(int)split.size(); i++){
    if(isNum(split[i])) num.push(stoi(split[i]));
    else if(!num.empty()){
      if(split[i] == "+"){
        double a = num.top();
        num.pop();
        double b = num.top();
        num.pop();
        num.push(a+b);
      }
      else if(split[i] == "-"){
        double a = num.top();
        num.pop();
        double b = num.top();
        num.pop();
        num.push(b-a);
      }
      else if(split[i] == "*"){
        double a = num.top();
        num.pop();
        double b = num.top();
        num.pop();
        num.push(a*b);        
      }
      else if(split[i] == "/"){
        double a = num.top();
        num.pop();
        double b = num.top();
        num.pop();
        num.push(b/a);
      }
      else if(split[i] == "%"){
        double a = num.top();
        num.pop();
        double b = num.top();
        num.pop();
        num.push(fmod(b,a)); // modulo for doubles
      }
      else if(split[i] == "^"){
        double a = num.top();
        num.pop();
        double b = num.top();
        num.pop();
        num.push(pow(b,a));
      }
    }
  }
  cout<<fixed<<setprecision(1);
  cout<<num.top()<<"\n";
}