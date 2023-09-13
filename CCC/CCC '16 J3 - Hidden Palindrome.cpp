#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// https://dmoj.ca/problem/ccc16j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string str;
  set<int> l;
  cin>>str;
  for(int i = 0; i<(int)str.size(); i++){

    for(int j = 1; j<=(int)str.size(); j++){
      string p = str.substr(i,j);
      string temp = p;
      reverse(temp.begin(), temp.end());
      if(p == temp) l.insert(p.size());
    }
  }
  cout<<*l.rbegin()<<"\n";
}