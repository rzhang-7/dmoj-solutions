#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/coci08c2p3

int N, sour[11], bit[11], ans = INT32_MAX;

void getComb(int i, int n, vector<int>& comb){
  if(i>n){
    if(comb.empty()) return;
    int totSour = 1, totBit = 0;
    for(int idx : comb){
      totSour *= sour[idx];
      totBit += bit[idx];
    }
    ans = min(ans, abs(totSour-totBit));
    return;
  }
  getComb(i+1, n, comb); // don't choose 1
  comb.push_back(i);
  getComb(i+1, n, comb);
  comb.pop_back();
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>N;
  for(int i = 1; i<=N; i++){
    cin>>sour[i]>>bit[i];
  }
  vector<int> comb;
  getComb(1, N, comb);
  cout<<ans<<"\n";
}