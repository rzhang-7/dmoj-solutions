#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// https://dmoj.ca/problem/sac22cc5jp3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,q,com,index;
  string name;
  cin>>n>>q;
  vector<unordered_set<string>> mediaList(n);
  for(int i = 0; i<q; i++){
    cin>>com>>index>>name;
    if(com == 1){      
      mediaList[index-1].count(name) > 0 ? cout<<1<<"\n" : cout<<0<<"\n";
    }
    else mediaList[index-1].insert(name);
  }
}