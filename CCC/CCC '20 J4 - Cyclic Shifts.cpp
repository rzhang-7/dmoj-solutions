#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/ccc20j4

deque<char> dq;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string t, s;
  cin>>t>>s;
  for(int i = 0; i<(int)s.length(); i++){
    dq.push_back(s[i]);
  }
  for(int i = 0; i<(int)s.length(); i++){
    string str = string(dq.begin(), dq.end());
    if(t.find(str) != -1){
      cout<<"yes\n";
      return 0;
    }
    char temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
  }
  cout<<"no\n";
}