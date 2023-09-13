#include <iostream>
#include <set>
using namespace std;

// https://dmoj.ca/problem/usaco19decbronze2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string m;
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    set<string> taken;    
    for(int j = 0; j<n-i+1; j++){
      string str;
      for(int k = 0; k<i; k++){
        str += m[j+k];
      }
      taken.insert(str);
    }
    if(taken.size() == n-i+1){
      cout<<i<<"\n";
      break;
    }
  }
}

/*
  int n;
  string m;
  cin>>n>>m;
  string sub = "";
  for(int i = 0; i<=n; i++){
    sub = m.substr(0,i);
    if(m.find(sub,m.find(sub) + 1) != string::npos)     
      continue;
    else break;
  }
  cout<<sub.length()<<"\n";
*/