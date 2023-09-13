#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/dwite07c1p4

int H, S, block[11], ans = INT32_MAX;

void getComb(int i, int n, vector<int>& comb){
  if(i>n){
    int sum = 0;
    if(comb.empty()) return;
    if((int)comb.size() < ans){
      for(int x : comb){
      sum += block[x];
      }
      if(sum == H) ans = comb.size();
    }
    return;
  }
  getComb(i+1, n, comb);
  comb.push_back(i);
  getComb(i+1, n, comb);
  comb.pop_back();
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>H>>S;
  for(int i = 1; i<=S; i++){
    cin>>block[i];
  }
  vector<int> comb;
  getComb(1, S, comb);
  cout<<(ans == INT32_MAX ? 0 : ans)<<"\n";
}