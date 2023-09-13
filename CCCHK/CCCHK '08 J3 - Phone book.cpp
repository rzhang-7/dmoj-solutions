#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/hkccc08j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, d, p, max = 0;
  string name, fav = "";
  map<int,pair<string,int>> pNums;
  cin>>n;
  while(n--){
    cin>>name>>p;
    pNums[p].first = name;
  }
  cin>>d;
  while(d--){
    cin>>p;
    pNums[p].second += 1;
  }
  for(auto x: pNums){
    if(x.second.second > max){
      max = x.second.second;
      fav = x.second.first;
    }
  }
  cout<<fav<<"\n";
}