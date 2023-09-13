#include <iostream>
#include <set>
using namespace std;

// https://dmoj.ca/problem/coci18c4p1

int main() {
  cin.sync_with_stdio(0); 
  cin.tie(0);
  char owner, w, l;
  int n;
  set<char> wand;
  cin>>owner>>n;
  wand.insert(owner);
  while(n--){
    cin>>w>>l;
    if(l == owner){
      owner = w;
      wand.insert(owner);
    }
  }
  cout<<owner<<"\n"<<wand.size()<<"\n";
}