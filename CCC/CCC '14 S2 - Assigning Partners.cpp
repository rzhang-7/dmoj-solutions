#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// https://dmoj.ca/problem/ccc14s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string name;
  unordered_map<string,string> total;
  vector<string> p1, p2;
  bool good = true;
  cin>>n;
  for(int i = 0; i < n; i++){
    cin>>name;
    p1.push_back(name);
  }
  for(int i = 0; i < n; i++){
    cin>>name;
    p2.push_back(name);
    // total[p1[i]] = name;
  }
  for(int i = 0; i < n; i++){
    total[p1[i]] = p2[i];
  }
  for(auto x : total){
    if(x.first != total[x.second]){ // || x.first == total[x.first]
      good = false; //cout<<"bad\n";
      break; // return 0;
    } 
    else if(x.first == total[x.first]){
      good = false;
      break;
    }
  }
  good ? cout<<"good\n" : cout<<"bad\n";
}