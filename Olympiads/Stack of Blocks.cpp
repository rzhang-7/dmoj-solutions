#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/oly20practice27

int N, T, block[21], ans = INT32_MAX;

void getComb(int i, int n, vector<int>& comb){
  if(i > n){
    if(comb.empty()) return;
    int h = 0;
    for(int x : comb){
      h += block[x];
    }
    if(h >= T){
      ans = min(ans, h - T);
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
  vector<int> comb;
  cin>>N>>T;
  for(int i = 1; i<=N; i++){
    cin>>block[i];
  }
  getComb(1, N, comb);
  if(ans==INT32_MAX) 
    cout<<-1<<"\n";
  else 
    cout<<ans<<"\n";
}