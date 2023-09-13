#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/sac22cc3jp4

int q;

void convert(int b1, string n, int b2){
  int num = 0;
  string ans = "";
  stack<int> stk;
  // can also use stoi(n, 0, b1)
  for(int i = 0; i<(int)n.length(); i++){
    num += (int)(n[(int)n.length()-i-1]-'0') * pow(b1,i);
  } 
  
  while(num != 0){
    stk.push(num%b2);
    num /= b2;
  }
  while(!stk.empty()){
    ans += stk.top()+'0';
    stk.pop();
  }
  cout<<ans<<"\n";
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>q;
  for(int i = 0, b1, b2; i<q; i++){
    string n;
    cin>>b1>>n>>b2;
    convert(b1,n,b2);
  }
}