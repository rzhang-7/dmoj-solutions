#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc19j3

int n; 
string s;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int count = 1;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>s;
    for(unsigned j = 0; j < s.length(); j++){
      if(s[j] == s[j+1]) count++;
      else{
        cout<<count<<" "<<s[j]<<" ";
        count = 1;
      }
    }
    cout<<"\n";
  }
}