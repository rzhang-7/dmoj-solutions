#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dmopc14c2p2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  int cut = 0;
  string l;
  cin>>n>>l;
  vector<char> log(l.begin(),l.end());
  vector<string> nonDef;
  
  string part = "";
  for(int i = 0; i<n; i++){
    if(log[i] == 'O') part += log[i];
    if((log[i] == 'X' || i == n-1) && part.length() > 0){
      nonDef.push_back(part);
      cut++;
      part = "";
    }
  }
  
  cout<<cut<<"\n";
  for(auto c : nonDef){
    cout<<c<<"\n";
  }
}