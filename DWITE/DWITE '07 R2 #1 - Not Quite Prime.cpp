#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dwite07c2p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0, n; i<5; i++){
    vector<int> v;
    cin>>n;
    if(n < 4){
      cout<<"not\n";
      continue;
    }
    for(int j = 2; j*j<=n; j++){
      while(n%j==0){ 
        n/=j;
        v.push_back(j);
      }
    }
    if(n>1) v.push_back(n);
    if((int)v.size()>2 || (int)v.size()==1) cout<<"not\n";
    else cout<<"semiprime\n";
  }
}