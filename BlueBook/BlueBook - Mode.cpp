#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/p172ex8

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, max = 0;
  map<int,int> count;
  for(cin>>n; n != -1; cin>>n){
    count[n]++;
  }

  for(auto it = count.begin(); it != count.end(); ++it){
    if(it->second > max){
      max = it->second;
    }
  }

  for(auto it = count.begin(); it != count.end(); ++it){
    if(it->second == max){
      cout<<it->first<<"\n";
    }
  }
}