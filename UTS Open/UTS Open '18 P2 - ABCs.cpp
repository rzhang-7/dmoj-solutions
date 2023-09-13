#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/utso18p2

int A[4], B[4], C[4], ans; bool valid[4];

void getComb(int i, int n, vector<int>& comb){
  if(i>n){
    int sum = 0;
    for(int x : comb){
      if(valid[x]) sum += C[x];
    }
    ans = max(sum, ans);
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
  for(int i = 1; i<=3; i++){
    cin>>A[i];
  }
  for(int i = 1; i<=3; i++){
    cin>>B[i];
  }
  for(int i = 1; i<=3; i++){
    cin>>C[i];
  }
  for(int i = 1; i<=3; i++){
    if(B[i] == A[i==1?3:i-1]) valid[i] = true;
  }
  vector<int> comb;
  getComb(1, 3, comb);
  cout<<ans<<"\n";
}