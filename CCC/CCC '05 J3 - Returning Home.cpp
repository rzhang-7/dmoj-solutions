#include <iostream>
#include <stack>
using namespace std;

// https://dmoj.ca/problem/ccc05j3

stack<string> d, s;
string dir, street;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

  while(street != "SCHOOL"){
    cin>>dir>>street;
    d.push(dir); s.push(street);
  }
  s.pop();
  while(!s.empty()){
    cout<<"Turn "<<(d.top()=="L"?"RIGHT ":"LEFT ")<<"onto "<<s.top()<<" street.\n";
    d.pop(); s.pop();
  }
  cout<<"Turn "<<(d.top()=="L"?"RIGHT ":"LEFT ")<<"into your HOME.\n";
}