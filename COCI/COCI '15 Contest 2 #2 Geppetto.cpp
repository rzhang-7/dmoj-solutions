#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/coci15c2p2

const int MM = 401;

int N, M, a[MM], b[MM], ans = 0;
vector<vector<int>> vvi;

void getComb(int i, int n, vector<int>& comb){
  if(i>n){
    vector<int> vi;
    for(int x : comb){
      vi.push_back(x);
    }
    vvi.push_back(vi);
    ans++;
    return;
  }
  getComb(i+1, n, comb);
  comb.push_back(i);
  getComb(i+1, n, comb);
  comb.pop_back();
}

bool find(vector<int> v, int n){
  for(int i : v){
    if(i == n) return true;
  }
  return false;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  vector<int> comb;
  cin>>N>>M;

  for(int i = 1; i<=M; i++){
    cin>>a[i]>>b[i];
  }
  getComb(1, N, comb);
  for(auto v : vvi){
    for(int i = 1; i<=M; i++){
      if(find(v,a[i]) && find(v,b[i])) ans--;
    }
  }
  cout<<ans<<"\n";
}